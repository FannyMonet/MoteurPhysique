#include "stdafx.h"
#include "RigidBody.h"
using namespace std;

# define M_PI           3.14159265358979323846  /* pi */


RigidBody::RigidBody(){}

RigidBody::RigidBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _rotation, float _linearDamping = 0.7, float _angularDamping = 0.7)
{
	position = _position;
	velocity = _velocity;
	rotation = _rotation;
	orientation = Quaternion(1, 0, 0, 0);
	transformMatrice = orientation.convertToMatrice4(position);
	forceAccum = vecteur3D();
	torqueAccum = vecteur3D();
	dragGenerator = DragGenerator();
	linearDamping = _linearDamping;
	angularDamping = _angularDamping;
	inverseMass = 1;
	points = new vecteur3D[8];
}

void RigidBody::calculDonneesDerivees()
{
	transformMatrice = orientation.convertToMatrice4(position);
	Matrice3 transformMatrice3 = Matrice3(	transformMatrice.coef[0], transformMatrice.coef[1], transformMatrice.coef[2],
											transformMatrice.coef[4], transformMatrice.coef[5], transformMatrice.coef[6],
											transformMatrice.coef[8], transformMatrice.coef[9], transformMatrice.coef[10]);
	inverseInertieTensor = transformMatrice3.Multiplication(inverseInertieTensor.Multiplication(transformMatrice3.inverse()));
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
	vecteur3D accelerationAngulaire = torqueAccum.produitMatriciel(inverseInertieTensor);
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
	transformPoints();
	clearAccumulators();
}
void RigidBody::updatePosition(float duree)
{
	position.x = position.x + (float)velocity.x * duree;
	position.y = position.y + (float)velocity.y * duree;
	position.z = position.z + (float)velocity.z * duree;
}
void RigidBody::updateOrientation(float duree)
{
	orientation.updateVelociteAngulaire(torqueAccum, duree);
}
void RigidBody::clearAccumulators()
{
	forceAccum = vecteur3D(0, 0, 0);
	torqueAccum = vecteur3D(0, 0, 0);
}