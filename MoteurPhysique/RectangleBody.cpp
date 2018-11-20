#include "stdafx.h"
#include "RectangleBody.h"


RectangleBody::RectangleBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _orientation, vecteur3D dim, vecteur3D pos) : RigidBody(_position, _velocity, _orientation)
{
	dimensions = dim;
	position = pos;
}
