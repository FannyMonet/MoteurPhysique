#include "stdafx.h"
#include "RigidBody.h"

# define M_PI           3.14159265358979323846  /* pi */

RigidBody::RigidBody(){}

RigidBody::RigidBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _orientation, vecteur3D _rotation, float _linearDamping = 0.7, float _angularDamping = 0.7)
{
	position = vecteur3D(_position);
	velocity = vecteur3D(_velocity);
	rotation = vecteur3D(_rotation);
	orientation = toQuaternion(_orientation);
	transformMatrice = orientation.convertToMatrice3();
	/*transformMatrice = Matrice3(position.x, 0, 0,
								0, position.y, 0,
								0, 0, position.z);*/
	forceAccum = vecteur3D();
	torqueAccum = vecteur3D();
	dragGenerator = DragGenerator();//vk1 et vk2
	inverseInertieTensor = getInertieTensor().inverse();
	linearDamping = _linearDamping;
	angularDamping = _angularDamping;
}

Matrice3 RigidBody::calculDonneesDerivees()
{
	// Calcul transformMatrice
	transformMatrice = orientation.convertToMatrice3();
	inverseInertieTensor = transformMatrice.Multiplication(inverseInertieTensor.Multiplication(transformMatrice.inverse()));
	return Matrice3();
}
void RigidBody::addForceAtPoint(vecteur3D force, vecteur3D point)
{
	point.worldToLocal(transformMatrice.inverse());
	forceAccum = vecteur3D(forceAccum.x + force.x, forceAccum.y + force.y, forceAccum.z + force.z);
	torqueAccum = vecteur3D(torqueAccum.x + point.x * force.x, torqueAccum.y + point.y * force.y, torqueAccum.z + point.z * force.z);
}

void RigidBody::addForceAtBodyPoint(vecteur3D force, vecteur3D point)
{
	point.localToWorld(transformMatrice);
	addForceAtPoint(force, point);
}

void RigidBody::Integrer(float duree)
{
	vecteur3D accelerationLineaire = vecteur3D(	inverseMass * forceAccum.x, 
												inverseMass * forceAccum.y, 
												inverseMass * forceAccum.z);
	vecteur3D accelerationAngulaire = torqueAccum.localToWorld(inverseInertieTensor);
	velocity = vecteur3D(	velocity.x * pow(linearDamping, duree) + accelerationLineaire.x * duree, 
							velocity.y * pow(linearDamping, duree) + accelerationLineaire.y * duree,
							velocity.z * pow(linearDamping, duree) + accelerationLineaire.z * duree
	);
	rotation = vecteur3D(	rotation.x * pow(angularDamping, duree) + accelerationAngulaire.x * duree,
							rotation.y * pow(angularDamping, duree) + accelerationAngulaire.y * duree,
							rotation.z * pow(angularDamping, duree) + accelerationAngulaire.z * duree);
	dragGenerator.updateForceRigidBody(velocity, rotation, &forceAccum, &torqueAccum, duree);
	updatePosition(duree);
	updateOrientation(duree);
	
	calculDonneesDerivees();
	clearAccumulators();
}
void RigidBody::updatePosition(float duree)
{
	position.x = position.x + velocity.x * duree;
	position.y = position.y + velocity.y * duree;
	position.z = position.z + velocity.y * duree;
}
void RigidBody::updateOrientation(float duree)
{
	orientation.x = orientation.x + rotation.x * duree;
	orientation.y = orientation.y + rotation.y * duree;
	orientation.z = orientation.z + rotation.y * duree;
}
void RigidBody::clearAccumulators()
{
	forceAccum = vecteur3D(0, 0, 0);
	torqueAccum = vecteur3D(0, 0, 0);
}
//source: wikipedia https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
static vecteur3D toEulerAngle(const Quaternion& q) 
{
	double roll;
	double pitch;
	double yaw;
	// roll (x-axis rotation)
	double sinr_cosp = +2.0 * (q.w * q.x + q.y * q.z);
	double cosr_cosp = +1.0 - 2.0 * (q.x * q.x + q.y * q.y);
	roll = atan2(sinr_cosp, cosr_cosp);

	// pitch (y-axis rotation)
	double sinp = +2.0 * (q.w * q.y - q.z * q.x);
	if (fabs(sinp) >= 1)
		pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		pitch = asin(sinp);

	// yaw (z-axis rotation)
	double siny_cosp = +2.0 * (q.w * q.z + q.x * q.y);
	double cosy_cosp = +1.0 - 2.0 * (q.y * q.y + q.z * q.z);
	yaw = atan2(siny_cosp, cosy_cosp);
	return vecteur3D(roll, pitch, yaw);
}
static Quaternion toQuaternion(vecteur3D orientation)
{
	double roll = orientation.x;
	double pitch = orientation.y;
	double yaw = orientation.z;
	// Abbreviations for the various angular functions
	double cy = cos(yaw * 0.5);
	double sy = sin(yaw * 0.5);
	double cr = cos(roll * 0.5);
	double sr = sin(roll * 0.5);
	double cp = cos(pitch * 0.5);
	double sp = sin(pitch * 0.5);

	Quaternion q;
	q.w = cy * cr * cp + sy * sr * sp;
	q.x = cy * sr * cp - sy * cr * sp;
	q.y = cy * cr * sp + sy * sr * cp;
	q.z = sy * cr * cp - cy * sr * sp;
	return q;
}
Matrice3 RigidBody::getInertieTensor()
{
	return Matrice3();
}