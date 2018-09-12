#pragma once
#include <vector>
#include "vecteur.h"
using namespace std;

class particule
{
public:
	float x;
	float y;
	float z;
	vecteur vitesse;

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz)
	{
		vitesse = vecteur(vitx, vity, vitz);
		x = posx;
		y = posy;
		z = posz;
	};

	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);

};
