#pragma once
#include "vecteur3D.h"
#include "Primitive.h"

class Contact
{
public:
	Contact();
	vecteur3D contactPoint;
	vecteur3D normale;
	float interpenetration;
};

