#pragma once
#include "vecteur3D.h"
#include "RigidBody.h"

class RectangleBody : RigidBody
{
public:
	vecteur3D dimensions;
	vecteur3D position;

	RectangleBody(vecteur3D position, vecteur3D velocity, vecteur3D orientation, vecteur3D rotation, vecteur3D dim, vecteur3D pos);
	virtual Matrice3 getInertieTensor();
};

