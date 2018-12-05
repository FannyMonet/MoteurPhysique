#pragma once
#include "Primitive.h"
class Plane :
	public Primitive
{
public:
	Plane();
	vecteur3D normal;
	float offset;
};

