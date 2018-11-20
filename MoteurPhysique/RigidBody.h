#pragma once
#include "vecteur3D.h"
#include "Quaternion.h"

class RigidBody
{
public:
	float inverseMass;
	float linearDampling;
	vecteur3D position;
	vecteur3D velocity;
	Quaternion orientation;
	vecteur3D rotation;
	Matrice3 transformMatrice;

	RigidBody();
};

