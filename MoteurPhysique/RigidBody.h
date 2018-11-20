#pragma once
#include "vecteur3D.h"
#include "Quaternion.h"

class RigidBody
{
public:
	float inverseMass;
	float linearDamping;
	float angularDamping;
	vecteur3D position;
	vecteur3D velocity;
	Quaternion orientation;
	vecteur3D rotation;
	Matrice3 transformMatrice;
	Matrice3 inverseInertieTensor;

	RigidBody();

	Matrice3 calculDonneesDerivees();
	void addForceAtPoint(vecteur3D force, vecteur3D point);
	void addForceAtBodyPoint(vecteur3D force, vecteur3D point);
	void Integrer(float duree);
};

