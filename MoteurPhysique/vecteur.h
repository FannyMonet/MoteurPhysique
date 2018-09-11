#include "stdafx.h"

#include <vector>
using namespace std;

class vecteur 
{
public:
	float dx;
	float dy;
	float dz;
	vecteur(float dx,float dy,float dz)
	{
		vector<float> test(3, 0);
		test[0] = dx ;
		test[1] = dy;
		test[2] = dz;
	};
	vector<int> Addition(vector<int> a, vector<int> b, int dim);
	int Produit_Scalaire(vector<int> a, vector<int> b, int dim);
	vector<int> Produit_de_Composante(vector<int> a, vector<int> b, int dim);
	double Norme(vector<int> a, int dim);
	vector<int> Multiplication_Scalaire(vector<int> a, int k, int dim);
	//Calcul_Integral();
};

