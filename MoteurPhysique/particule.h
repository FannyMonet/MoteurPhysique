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
	vecteur* vitesse = new vecteur( dx, dy, dz);

	vector<float> position;
	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);

};
