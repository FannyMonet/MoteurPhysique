#pragma once
#include "vecteur3D.h"

class Contact
{
public:
	vecteur3D contactPoint;
	vecteur3D normale;
	float interpenetration;
};

