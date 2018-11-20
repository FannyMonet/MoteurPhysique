#pragma once
#include "vecteur3D.h"
#include "Matrice3.h"

class Quaternion
{
public:
	double w;
	double x;
	double y;
	double z;

	Quaternion();
	Quaternion(double w, double x, double y, double z);
	Quaternion(Quaternion* q);
	void normalize();
	Quaternion operator*=(Quaternion q);
	void effectuerRotation(vecteur3D v);
	void updateVelociteAngulaire(vecteur3D velocite, float temps);
	Matrice3 convertToMatrice3();
	Matrice4 convertToMatrice4();
};

