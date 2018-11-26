#include "stdafx.h"
#include "RectangleBody.h"
#include <iostream>

using namespace std;

RectangleBody::RectangleBody(){}
RectangleBody::RectangleBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _orientation, vecteur3D _rotation, float _linearDamping, float _angularDamping, vecteur3D dim) : RigidBody(_position, _velocity, _orientation, _rotation, _linearDamping, _angularDamping)
{
	dimensions = dim;
}
Matrice3 RectangleBody::getInertieTensor()
{
	return Matrice3(1/12 * getMass() * (dimensions.y * dimensions.y * dimensions.z * dimensions.z), 0, 0,
					0, 1 / 12 * getMass() * (dimensions.x * dimensions.x * dimensions.z * dimensions.z), 0,
					0, 0, 1 / 12 * getMass() * (dimensions.x * dimensions.x * dimensions.y * dimensions.y)
	);
}
