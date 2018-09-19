#include "stdafx.h"
#include "vecteur.h"
#include <iostream>

using namespace std;

float* vecteur::Addition(float* v)
{
	float result[3];
	result[0] = v[0] + x;
	result[1] = v[1] + y;
	result[2] = v[2] + z;
	return result;
}

float vecteur::Produit_Scalaire(float* v)
{
	return v[0] * x + v[1] * y + v[2] * z;
}

float* vecteur::Produit_de_Composante(float* v)
{
	float result[3];
	result[0] = v[0] * x;
	result[1] = v[1] * y;
	result[2] = v[2] * z;
	return result;
}

double vecteur::Norme()
{
	return sqrt(x*x + y*y + z*z);
}

float* vecteur::Multiplication_Scalaire(int k)
{
	float result[3];
	result[0] = x * k;
	result[1] = y * k;
	result[2] = z * k;
	return result;
}
