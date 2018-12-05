#pragma once
#include "vecteur3D.h"

class Contact
{
public:
	Contact();
	vecteur3D contactPoint;
	vecteur3D normale;
	float interpenetration;
};

