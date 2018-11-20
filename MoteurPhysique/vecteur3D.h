#pragma once
#include "Matrice3.h"
#include "Matrice4.h"

class vecteur3D
{
public:
	
	float x;
	float y;
	float z;

	vecteur3D();
	vecteur3D(float dx, float dy, float dz);

	vecteur3D Addition(vecteur3D &vec);
	float Produit_Scalaire(vecteur3D &vec);
	vecteur3D Produit_de_Composante(vecteur3D &vec);
	double Norme();
	vecteur3D Multiplication_Scalaire(float k);
	vecteur3D addForce(vecteur3D &force);
	vecteur3D clearAccum();
	vecteur3D localToWorld(Matrice3);
	vecteur3D worldToLocal(Matrice3);
};

