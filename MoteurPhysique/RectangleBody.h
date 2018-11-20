#pragma once
#include "vecteur3D.h"
#include "RigidBody.h"

class RectangleBody : RigidBody
{
public:
	vecteur3D dimensions;
	vecteur3D position;

	RectangleBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _orientation, vecteur3D dim, vecteur3D pos);
};

