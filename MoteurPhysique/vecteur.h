#pragma once
#include "stdafx.h"

using namespace std;

class vecteur
{
public:

	float x;
	float y;
	float z;

	vecteur()
	{
		x = 0;
		y = 0;
		z = 0;
	};
	vecteur(float dx,float dy,float dz)
	{
		x = dx;
		y = dy;
		z = dz;
	};
	float* Addition(float* vec);
	float Produit_Scalaire(float* v);
	float* Produit_de_Composante(float*);
	double Norme();
	float* Multiplication_Scalaire(int k);
};

