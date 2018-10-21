#pragma once
#include "vecteur.h"

class vecteur2D : public vecteur
{
public:
	float x;
	float y;

	vecteur2D();
	vecteur2D(float dx, float dy);

	virtual vecteur Addition(vecteur2D &vec);
	virtual float Produit_Scalaire(vecteur2D &vec);
	virtual vecteur Produit_de_Composante(vecteur2D &vec);
	virtual double Norme();
	virtual vecteur Multiplication_Scalaire(float k);
	virtual vecteur addForce(vecteur2D &force);
	virtual vecteur clearAccum();
};

