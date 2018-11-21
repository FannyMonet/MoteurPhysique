#include "stdafx.h"
#include "RectangleBody.h"


RectangleBody::RectangleBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _orientation, vecteur3D _rotation, vecteur3D dim, vecteur3D pos) : RigidBody(_position, _velocity, _orientation, _rotation)
{
	dimensions = dim;
	position = pos;
}
Matrice3 RectangleBody::getInertieTensor()
{
	return Matrice3(1/12 * getMass() * (dimensions.y * dimensions.y * dimensions.z * dimensions.z), 0, 0,
					0, 1 / 12 * getMass() * (dimensions.x * dimensions.x * dimensions.z * dimensions.z), 0,
					0, 0, 1 / 12 * getMass() * (dimensions.x * dimensions.x * dimensions.y * dimensions.y)
	);
}
