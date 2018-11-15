#pragma once
#include "stdafx.h"
#include <vector>
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
	float rayon;

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz, int n, float d, float m, float r)
	{
		numero = n;
		dumping = d;
		masse = m;
		position3D = vecteur3D(posx, posy, posz);
		vitesse3D = vecteur3D(vitx, vity, vitz);
		accumForce3D = vecteur3D(0, 0, 0);
		dimension = 3;
		rayon = r;
	};
	particule(float posx, float posy, float vitx, float vity, int n, float d, float m, float r)
	{
		numero = n;
		dumping = d;
		masse = m;
		position2D = vecteur2D(posx, posy);
		vitesse2D = vecteur2D(vitx, vity);
		accumForce2D = vecteur2D(0, 0);
		dimension = 2;
		rayon = r;
	};
	particule()
	{
		numero = 0;
		dumping = 0;
		masse = 0;
		position3D = vecteur3D(0, 0, 0);
		vitesse3D = vecteur3D(0, 0, 0);
		accumForce3D = vecteur3D(0, 0, 0);
		dimension = 3;
		rayon = 5;
	};
	particule(const particule& particule)
	{
		dimension = particule.dimension;
		numero = particule.numero;
		dumping = particule.dumping;
		masse = particule.masse;
		rayon = particule.rayon;
		if (dimension == 3)
		{
			
			position3D = vecteur3D(particule.position3D.x, particule.position3D.y, particule.position3D.z);
			vitesse3D = vecteur3D(particule.vitesse3D.x, particule.vitesse3D.y, particule.vitesse3D.z);
			accumForce3D = vecteur3D(particule.accumForce3D.x, particule.accumForce3D.y, particule.accumForce3D.z);
		}
		else if (dimension == 2)
		{
			position2D = vecteur2D(particule.position2D.x, particule.position2D.y);
			vitesse2D = vecteur2D(particule.vitesse2D.x, particule.vitesse2D.y);
			accumForce2D = vecteur2D(particule.accumForce2D.x, particule.accumForce2D.y);
		}
	}

	int Inverse_Masse(int Masse);
	void Integrer(float temps);
	void addForce(const vecteur3D &force);
	void addForce(const vecteur2D &force);
	void clearAccum();
	float distance(const particule &particule);
};
