#include "stdafx.h"
#include "RigidBody.h"


RigidBody::RigidBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _orientation)
{
	position = _position;
	velocity = _velocity;
	//dragGenerator = DragGenerator();//vk1 et vk2
	transformMatrice = Matrice3(position.x, 0, 0,
								0, position.y, 0,
								0, 0, position.z);
}

Matrice3 RigidBody::calculDonneesDerivees()
{
	// Calcul transformMatrice
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
	//dragGenerator.updateForceRigidBody(this, duree);
	updatePosition(duree);
	updateOrientation(duree);
	
	//Calculer les "derived data" // Transform matrix et I-1
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
