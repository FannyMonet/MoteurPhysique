#include "stdafx.h"
#include "RectangleBody.h"
#include <iostream>

using namespace std;

RectangleBody::RectangleBody(){}
RectangleBody::RectangleBody(vecteur3D _position, vecteur3D _velocity, vecteur3D _rotation, float _linearDamping, float _angularDamping, vecteur3D dim) : RigidBody(_position, _velocity, _rotation, _linearDamping, _angularDamping)
{
	dimensions = dim;
	inverseInertieTensor = this->getInertieTensor().inverse();
	points[0] = vecteur3D(position.x + dimensions.x / 2, position.x + dimensions.y / 2, position.x + dimensions.z / 2);
	points[1] = vecteur3D(position.x + dimensions.x / 2, position.x + dimensions.y / 2, position.x - dimensions.z / 2);
	points[2] = vecteur3D(position.x + dimensions.x / 2, position.x - dimensions.y / 2, position.x + dimensions.z / 2);
	points[3] = vecteur3D(position.x + dimensions.x / 2, position.x - dimensions.y / 2, position.x - dimensions.z / 2);
	points[4] = vecteur3D(position.x - dimensions.x / 2, position.x + dimensions.y / 2, position.x + dimensions.z / 2);
	points[5] = vecteur3D(position.x - dimensions.x / 2, position.x + dimensions.y / 2, position.x - dimensions.z / 2);
	points[6] = vecteur3D(position.x - dimensions.x / 2, position.x - dimensions.y / 2, position.x + dimensions.z / 2);
	points[7] = vecteur3D(position.x - dimensions.x / 2, position.x - dimensions.y / 2, position.x - dimensions.z / 2);
}
Matrice3 RectangleBody::getInertieTensor()
{
	Matrice3 tempMat = Matrice3((float)1/12 * getMass() * (dimensions.y * dimensions.y * dimensions.z * dimensions.z), 0, 0,
		0, (float)1 / 12 * getMass() * (dimensions.x * dimensions.x * dimensions.z * dimensions.z), 0,
		0, 0, (float)1 / 12 * getMass() * (dimensions.x * dimensions.x * dimensions.y * dimensions.y)
	);
	return tempMat;
}