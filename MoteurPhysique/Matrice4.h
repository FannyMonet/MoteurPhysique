#pragma once
#include "vecteur4D.h"

class Matrice4
{
public:
	double coef[12];
	Matrice4();
	Matrice4(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9, double a10, double a11);
	Matrice4(double* coefTable);

	Matrice4 inverse();
	vecteur4D Multiplication(vecteur4D vec);
	Matrice4 Multiplication(Matrice4 mat);
};

