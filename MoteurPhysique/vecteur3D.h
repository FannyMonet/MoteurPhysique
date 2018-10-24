#pragma once
#include "vecteur.h"

class vecteur3D
{
public:
	
	float x;
	float y;
	float z;

	vecteur3D();
	vecteur3D(float dx, float dy, float dz);

	virtual vecteur3D Addition(vecteur3D &vec);
	virtual float Produit_Scalaire(vecteur3D &vec);
	virtual vecteur3D Produit_de_Composante(vecteur3D &vec);
	virtual double Norme();
	virtual vecteur3D Multiplication_Scalaire(float k);
	virtual vecteur3D addForce(vecteur3D &force);
	virtual vecteur3D clearAccum();
};

