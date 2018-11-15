#include "stdafx.h"
#include "Matrice3.h"

using namespace std;

Matrice3::Matrice3(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
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
}

Matrice3::Matrice3(double* coefTable)
{
	for (int i = 0; i < 9; i++)
	{
		coef[i] = coefTable[i];
	}
}
Matrice3::Matrice3()
{
	coef[0], coef[1], coef[2], coef[3], coef[4], coef[5], coef[6], coef[7], coef[8] = 0;
}
Matrice3 Matrice3::inverse()
{
	double det = coef[0]*coef[4]*coef[8] + coef[3]*coef[7]*coef[2] + coef[6]*coef[1]*coef[5] - coef[0]*coef[7]*coef[5] - coef[6]*coef[4]*coef[2] - coef[3]*coef[1]*coef[8];
	return Matrice3((coef[4] * coef[8] - coef[5] * coef[7]) / det,
					(coef[2] * coef[7] - coef[1] * coef[8]) / det,
					(coef[1] * coef[5] - coef[2] * coef[4]) / det,
					(coef[5] * coef[6] - coef[3] * coef[8]) / det,
					(coef[0] * coef[8] - coef[2] * coef[6]) / det,
					(coef[2] * coef[3] - coef[0] * coef[5]) / det,
					(coef[3] * coef[7] - coef[4] * coef[6]) / det,
					(coef[1] * coef[6] - coef[0] * coef[7]) / det,
					(coef[0] * coef[4] - coef[1] * coef[3]) / det);
}

Matrice3 Matrice3::transpose()
{
	return Matrice3(coef[0], coef[3], coef[6], coef[1], coef[4], coef[7], coef[2], coef[5], coef[8]);
}

vecteur3D Matrice3::Multiplication(vecteur3D vec)
{
	return vecteur3D(coef[0] * vec.x + coef[1] * vec.y + coef[2] * vec.z, coef[3] * vec.x + coef[4] * vec.y + coef[5] * vec.z, coef[6] * vec.x + coef[7] * vec.y + coef[8] * vec.z);
}

Matrice3 Matrice3::Multiplication(Matrice3 mat)
{
	return Matrice3(coef[0] * mat.coef[0] + coef[1] * mat.coef[3] + coef[2] * mat.coef[6],
					coef[0] * mat.coef[1] + coef[1] * mat.coef[4] + coef[2] * mat.coef[7],
					coef[0] * mat.coef[2] + coef[1] * mat.coef[5] + coef[2] * mat.coef[8],
					coef[1] * mat.coef[0] + coef[1] * mat.coef[3] + coef[2] * mat.coef[6],
					coef[1] * mat.coef[1] + coef[1] * mat.coef[4] + coef[2] * mat.coef[7],
					coef[1] * mat.coef[2] + coef[1] * mat.coef[5] + coef[2] * mat.coef[8],
					coef[2] * mat.coef[0] + coef[1] * mat.coef[3] + coef[2] * mat.coef[6],
					coef[2] * mat.coef[1] + coef[1] * mat.coef[4] + coef[2] * mat.coef[7],
					coef[2] * mat.coef[2] + coef[1] * mat.coef[5] + coef[2] * mat.coef[8]);
}