#pragma once
#include "vecteur3D.h"
#include "RigidBody.h"

class RectangleBody : RigidBody
{
public:
	vecteur3D dimensions;
	vecteur3D position;

	RectangleBody(vecteur3D position, vecteur3D velocity, vecteur3D orientation, vecteur3D rotation, float linearDamping, float angularDamping, vecteur3D dim);
	virtual Matrice3 getInertieTensor();
};

