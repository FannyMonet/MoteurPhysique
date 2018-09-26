
#pragma once
#include "stdafx.h"
#include <vector>
#include "vecteur.h"
using namespace std;

class particule
{
public:
	vecteur position = vecteur();
	vecteur vitesse = vecteur();
	vecteur accumForce = vecteur();
	int numero;
	float dumping;
	float masse;

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz, int n, int d, float m)
	{
		numero = n;
		dumping = d;
		masse = m;
		position = vecteur(posx, posy, posz);
		vitesse = vecteur(vitx, vity, vitz);
		accumForce = vecteur(0, 0, -9.81);
	};
	particule()
	{
		numero = 0;
		dumping = 0;
		masse = 0;
		position = vecteur(0, 0, 0);
		vitesse = vecteur(0, 0, 0);
		accumForce = vecteur(0, 0, -9.81);
	};
	particule(const particule& particule)
	{
		numero = particule.numero;
		dumping = particule.dumping;
		masse = particule.masse;
		position = vecteur(particule.position.x, particule.position.y, particule.position.z);
		vitesse = vecteur(particule.vitesse.x, particule.vitesse.y, particule.vitesse.z);
		accumForce = vecteur(particule.accumForce.x, particule.accumForce.y, particule.accumForce.z);
	}

	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);
	void addForce(const vecteur &force);
	void clearAccum();
};
