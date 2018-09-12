#include "stdafx.h"
#include <iostream>
#include <vector>
#include "particule.h"


int particule::Inverse_Masse(int Masse)
{
	int Inverse_Masse = 1/Masse;
	return Inverse_Masse;
}

void particule::Integrer(float temps)
{
	x = x + vitesse.vec[0] * temps;
	y = y + vitesse.vec[1]* temps;
	z = z + vitesse.vec[2]* temps;
	vitesse.vec[0] = vitesse.vec[0] * 0.7;// -9.81*temps;
	vitesse.vec[1] = vitesse.vec[1] * 0.7;// -9.81*temps;
	vitesse.vec[2] = vitesse.vec[2]*0.7 - 9.81*temps;
};