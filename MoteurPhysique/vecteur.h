#include "stdafx.h"

#include <vector>
using namespace std;

class vecteur 
{
public:

	float vec[3];
	vecteur()
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
	}
	vecteur(float dx,float dy,float dz)
	{
		vec[0] = dx;
		vec[1] = dy;
		vec[2] = dz;
	};
	float* Addition(float* vec);
	float Produit_Scalaire(float* v);
	float* Produit_de_Composante(float*);
	double Norme();
	float* Multiplication_Scalaire(int k);
	//Calcul_Integral();
};

