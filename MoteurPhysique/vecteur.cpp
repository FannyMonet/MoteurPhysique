//#include "vecteur.h"
#include "stdafx.h"
#include <iostream>
#include "vecteur.h"

#include <vector>
using namespace std;




std::vector<int> vecteur::Addition(std::vector<int> a, std::vector<int> b,int dim)
{
	vector<int> result (dim);
	for (int i = 0; i<dim; i++)
	{
		result[i] = a[i] + b[i];
	}
	return result;
}


int vecteur::Produit_Scalaire(vector<int> a, vector<int> b, int dim)
{
	int result = 0;
	for (int i = 0; i<dim; i++)
	{
		result += a[i] * b[i];
	}
	return result;
}

vector<int> vecteur::Produit_de_Composante(vector<int> a, vector<int> b,int dim)
{
	vector<int> result(dim);
	for (int i = 0; i<dim; i++)
	{
		result[i] = a[i] * b[i];
	}
	return result;
}

double vecteur::Norme(vector<int> a, int dim)
{
	double result = 0;
	for (int i = 0; i<dim; i++)
	{
		result += a[i]^2 ;
	}
	result = sqrt(result);
	return result;
	
}

vector<int> vecteur::Multiplication_Scalaire(vector<int> a, int k,int dim)
{
	vector<int> result(dim);
	for (int i = 0; i<dim; i++)
	{
		result[i] = a[i] * k;
	}
	return result;
}
