#pragma once
#include "stdafx.h"
#include <vector>
#include "vecteur.h"
#include "vecteur2D.h"
#include "vecteur3D.h"

class particule
{
public:
	vecteur2D position2D;
	vecteur3D position3D;
	vecteur2D vitesse2D;
	vecteur3D vitesse3D;
	vecteur2D accumForce2D;
	vecteur3D accumForce3D;
	int numero;
	float dumping;
	float masse;
	int dimension;

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz, int n, int d, float m)
	{
		numero = n;
		dumping = d;
		masse = m;
		position3D = vecteur3D(posx, posy, posz);
		vitesse3D = vecteur3D(vitx, vity, vitz);
		accumForce3D = vecteur3D(0, -9.81, 0);
		dimension = 3;
	};
	particule(float posx, float posy, float vitx, float vity, int n, int d, float m)
	{
		numero = n;
		dumping = d;
		masse = m;
		position2D = vecteur2D(posx, posy);
		vitesse2D = vecteur2D(vitx, vity);
		accumForce2D = vecteur2D(0, -9.81);
		dimension = 2;
	};
	particule()
	{
		numero = 0;
		dumping = 0;
		masse = 0;
		position3D = vecteur3D(0, 0, 0);
		vitesse3D = vecteur3D(0, 0, 0);
		accumForce3D = vecteur3D(0, -9.81, 0);
		dimension = 3;
	};
	particule(const particule& particule, int dim = 3)
	{
		dimension = dim;
		if (dim == 3)
		{
			numero = particule.numero;
			dumping = particule.dumping;
			masse = particule.masse;
			position3D = vecteur3D(particule.position3D.x, particule.position3D.y, particule.position3D.z);
			vitesse3D = vecteur3D(particule.vitesse3D.x, particule.vitesse3D.y, particule.vitesse3D.z);
			accumForce3D = vecteur3D(particule.accumForce3D.x, particule.accumForce3D.y, particule.accumForce3D.z);
		}
		else if (dim == 2)
		{
			numero = particule.numero;
			dumping = particule.dumping;
			masse = particule.masse;
			position2D = vecteur2D(particule.position2D.x, particule.position2D.y);
			vitesse2D = vecteur2D(particule.vitesse2D.x, particule.vitesse2D.y);
			accumForce2D = vecteur2D(particule.accumForce2D.x, particule.accumForce2D.y);
		}
	}

	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);
	void addForce(const vecteur3D &force);
	void addForce(const vecteur2D &force);
	void clearAccum();
};
