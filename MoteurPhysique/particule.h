
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

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz)
	{
		position = vecteur(posx, posy, posz);
		vitesse = vecteur(vitx, vity, vitz);
	};
	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);

};
