#pragma once
#include"vecteur3D.h"

class Sphere
{
public:
	Sphere();
	vecteur3D center;
	float rayon;
	Sphere(vecteur3D center, float rayon);
};

