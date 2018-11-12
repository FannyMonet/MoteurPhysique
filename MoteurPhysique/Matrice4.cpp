#include "stdafx.h"
#include "Matrice4.h"

Matrice4::Matrice4(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9, double a10, double a11)
{
	coef[0] = a0;
	coef[1] = a1;
	coef[2] = a2;
	coef[3] = a3;
	coef[4] = a4;
	coef[5] = a5;
	coef[6] = a6;
	coef[7] = a7;
	coef[8] = a8;
	coef[9] = a9;
	coef[10] = a10;
	coef[11] = a11;
}
Matrice4::Matrice4(double* coefTable)
{
	for (int i = 0; i < 9; i++)
	{
		coef[i] = coefTable[i];
	}
}
Matrice4::Matrice4()
{
	coef[0], coef[1], coef[2], coef[3], coef[4], coef[5], coef[6], coef[7], coef[8], coef[9], coef[10], coef[11] = 0;
}
Matrice4 Matrice4::inverse()
{
	double det = coef[8]*coef[5]*coef[2] + coef[4]*coef[9]*coef[2] + coef[8]*coef[1]*coef[6] - coef[0]*coef[9]*coef[6] - coef[4]*coef[1]*coef[10] + coef[0]*coef[5]*coef[10];

	double c4 = coef[9] * coef[6] * coef[3] - coef[5] * coef[10] * coef[3] - coef[9] * coef[2] * coef[7] + coef[1] * coef[10] * coef[7] + coef[5] * coef[2] * coef[11] - coef[1] * coef[6] * coef[11];
	double c8 = - coef[8] * coef[6] * coef[3] + coef[4] * coef[10] * coef[3] + coef[8] * coef[2] * coef[7] - coef[0] * coef[10] * coef[7] - coef[4] * coef[2] * coef[11] + coef[0] * coef[6] * coef[11];
	double c12 = coef[8] * coef[5] * coef[3] - coef[4] * coef[9] * coef[3] - coef[8] * coef[1] * coef[7] + coef[0] * coef[9] * coef[7] + coef[4] * coef[1] * coef[11] - coef[0] * coef[9] * coef[11];
	return Matrice4(-coef[9] * coef[6] + coef[5] * coef[10],
					coef[9] * coef[2] - coef[1] * coef[10],
					-coef[5] * coef[2] + coef[1] * coef[6],
					c4,
					coef[8] * coef[6] - coef[4] * coef[10],
					-coef[8] * coef[2] + coef[0] * coef[10],
					coef[4] * coef[2] - coef[0] * coef[6],
					c8,
					-coef[8] * coef[5] + coef[4] * coef[9],
					coef[8] * coef[1] - coef[0] * coef[9],
					-coef[4] * coef[1] + coef[0] * coef[5],
					c12);
}
vecteur4D Matrice4::Multiplication(vecteur4D vec)
{
	return vecteur4D(	coef[0] * vec.w + coef[1] * vec.x + coef[2] * vec.y + coef[3] * vec.z,
						coef[4] * vec.w + coef[5] * vec.x + coef[6] * vec.y + coef[7] * vec.z,
						coef[8] * vec.w + coef[9] * vec.x + coef[10] * vec.y + coef[11] * vec.z,
						vec.z);
}

Matrice4 Matrice4::Multiplication(Matrice4 mat)
{
	return Matrice4(coef[0] * mat.coef[0] + coef[1] * mat.coef[4] + coef[2] * mat.coef[8],
					coef[0] * mat.coef[1] + coef[1] * mat.coef[5] + coef[2] * mat.coef[9],
					coef[0] * mat.coef[2] + coef[1] * mat.coef[6] + coef[2] * mat.coef[10],
					coef[0] * mat.coef[3] + coef[1] * mat.coef[7] + coef[2] * mat.coef[11] + coef[3],
					coef[4] * mat.coef[0] + coef[5] * mat.coef[4] + coef[6] * mat.coef[8],
					coef[4] * mat.coef[1] + coef[5] * mat.coef[5] + coef[6] * mat.coef[9],
					coef[4] * mat.coef[2] + coef[5] * mat.coef[6] + coef[6] * mat.coef[10],
					coef[4] * mat.coef[3] + coef[5] * mat.coef[7] + coef[6] * mat.coef[11] + coef[7],
					coef[8] * mat.coef[0] + coef[9] * mat.coef[4] + coef[10] * mat.coef[8],
					coef[8] * mat.coef[1] + coef[9] * mat.coef[5] + coef[10] * mat.coef[9],
					coef[8] * mat.coef[2] + coef[9] * mat.coef[6] + coef[10] * mat.coef[10],
					coef[8] * mat.coef[3] + coef[9] * mat.coef[7] + coef[10] * mat.coef[11] + coef[11]);
}