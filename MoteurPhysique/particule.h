
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
	int numero;

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz, int n)
	{
		numero = n;
		position = vecteur(posx, posy, posz);
		vitesse = vecteur(vitx, vity, vitz);
	};
	particule()
	{
		numero = -1;
		position = vecteur(0, 0, 0);
		vitesse = vecteur(0, 0, 0);
	};
	particule(const particule& particule)
	{
		numero = particule.numero;
		position = vecteur(particule.position.x, particule.position.y, particule.position.z);
		vitesse = vecteur(particule.vitesse.x, particule.vitesse.y, particule.vitesse.z);
	}

	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);
};
