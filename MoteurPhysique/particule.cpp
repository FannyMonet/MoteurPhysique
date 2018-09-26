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
	position.x = position.x + vitesse.x * temps;
	position.y = position.y + vitesse.y* temps;
	position.z = position.z + vitesse.z* temps;
	vitesse.x = vitesse.x * 0.7;
	vitesse.y = vitesse.y * 0.7;
	vitesse.z = vitesse.z*0.7 - 9.81*temps;
}

void particule::addForce(const vecteur &force)
{
	accumForce.x += force.x;
	accumForce.y += force.y;
	accumForce.z += force.z;
}

void particule::clearAccum()
{
	accumForce.x = 0;
	accumForce.y = 0;
	accumForce.z = 0;
}