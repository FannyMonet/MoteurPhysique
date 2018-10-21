#pragma once
#include "vecteur.h"

class vecteur3D : public vecteur
{
public:
	
	float x;
	float y;
	float z;

	vecteur3D();
	vecteur3D(float dx, float dy, float dz);

	virtual vecteur Addition(vecteur3D &vec);
	virtual float Produit_Scalaire(vecteur3D &vec);
	virtual vecteur Produit_de_Composante(vecteur3D &vec);
	virtual double Norme();
	virtual vecteur Multiplication_Scalaire(float k);
	virtual vecteur addForce(vecteur3D &force);
	virtual vecteur clearAccum();
};

