#pragma once
#include "stdafx.h"

using namespace std;

class vecteur
{
	
public:


	vecteur() {}
	virtual vecteur Addition(vecteur &vec);
	virtual float Produit_Scalaire(vecteur &vec);
	virtual vecteur Produit_de_Composante(vecteur &vec);
	virtual double Norme();
	virtual vecteur Multiplication_Scalaire(float k);
	virtual vecteur addForce(vecteur &force);
	virtual vecteur clearAccum();
};

