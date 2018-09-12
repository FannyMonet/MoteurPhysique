#include "stdafx.h"
#include <iostream>
#include "vecteur.h"
#include <vector>
using namespace std;

float* vecteur::Addition(float* v)
{
	float result[3];
	for (int i = 0; i<3; i++)
	{
		result[i] = v[i] + vec[0];
	}
	return result;
}

float vecteur::Produit_Scalaire(float* v)
{
	float result;
	for (int i = 0; i < 3; i++)
	{
		result += v[i] * vec[i];
	}
	return result;
}

float* vecteur::Produit_de_Composante(float* v)
{
	float result[3];
	for (int i = 0; i < 3; i++)
	{
		result[i] = vec[i] * v[i];
	}
	return result;
}

double vecteur::Norme()
{
	double result = 0;
	for (int i = 0; i < 3; i++)
	{
		result += (int)vec[i] ^ 2;
	}
	result = sqrt(result);
	return result;
	
}

float* vecteur::Multiplication_Scalaire(int k)
{
	float result[3];
	for (int i = 0; i < 3; i++)
	{
		result[i] = vec[i] * k;
	}
	return result;
}
