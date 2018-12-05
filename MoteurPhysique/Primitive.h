#pragma once
#include "RigidBody.h"
class Primitive
{
public:
	Primitive();
	
	RigidBody * body;
	Matrice4 offset;
};

