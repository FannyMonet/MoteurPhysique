#pragma once
#include <vector>
using namespace std;

class particule
{
public:
	float x;
	float y;
	float z;
	vecteur vitesse = new vecteur(dx, dy, dz);

	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);

};
