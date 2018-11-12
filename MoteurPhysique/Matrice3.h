#pragma once
#include "vecteur3D.h"

class Matrice3
{
public:
	double coef[9];
	Matrice3(); 
	Matrice3(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);
	Matrice3(double* coefTable);

	Matrice3 inverse();
	Matrice3 transpose();
	vecteur3D Multiplication(vecteur3D vec);
	Matrice3 Multiplication(Matrice3 mat);
};
