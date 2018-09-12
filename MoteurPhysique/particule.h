
#pragma once
#include "stdafx.h"
#include <vector>
#include "vecteur.h"
using namespace std;

class particule
{
public:
	float x;
	float y;
	float z;
	vecteur vitesse = vecteur();

	particule(float posx, float posy, float posz, float vitx, float vity, float vitz)
	{
		vitesse = vecteur(vitx, vity, vitz);
		x = posx;
		y = posy;
		z = posz;
	};
	vector<float> position;
	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);

};
