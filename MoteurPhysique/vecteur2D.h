#pragma once

class vecteur2D
{
public:
	float x;
	float y;

	vecteur2D();
	vecteur2D(float dx, float dy);

	virtual vecteur2D Addition(vecteur2D &vec);
	virtual float Produit_Scalaire(vecteur2D &vec);
	virtual vecteur2D Produit_de_Composante(vecteur2D &vec);
	virtual double Norme();
	virtual vecteur2D Multiplication_Scalaire(float k);
	virtual vecteur2D addForce(vecteur2D &force);
	virtual vecteur2D clearAccum();
};

