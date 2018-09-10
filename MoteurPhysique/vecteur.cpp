//#include "vecteur.h"
#include <iostream>
#include <vector>
#include "vecteur.h"
using namespace std;



vector<int> vecteur::Addition(vector<int> a, vector<int> b,int dim)
{
	vector<int> result (dim);
	for (unsigned i = 0; i<dim; i++)
	{
		result[i] = a[i] + b[i];
	}
	return result;
}


int vecteur::Produit_Scalaire(vector<int> a, vector<int> b, int dim)
{
	int result = 0;
	for (unsigned i = 0; i<dim; i++)
	{
		result += a[i] * b[i];
	}
	return result;
}

vector<int> vecteur::Produit_de_Composante(vector<int> a, vector<int> b,int dim)
{
	vector<int> result(dim);
	for (unsigned i = 0; i<dim; i++)
	{
		result[i] = a[i] * b[i];
	}
	return result;
}

int vecteur::Norme(vector<int> a, int dim)
{
	int result = 0;
	for (unsigned i = 0; i<dim; i++)
	{
		result += a[i]^2 ;
	}
	result = sqrt(result);
	return result;
	
}

vector<int> vecteur::Multiplication_Scalaire(vector<int> a, int k,int dim)
{
	vector<int> result(dim);
	for (unsigned i = 0; i<dim; i++)
	{
		result[i] = a[i] * k;
	}
	return result;
}