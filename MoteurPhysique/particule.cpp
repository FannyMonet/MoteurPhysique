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
	if (dimension == 3)
	{
		position3D.x = position3D.x + vitesse3D.x * temps;
		position3D.y = position3D.y + vitesse3D.y* temps;
		position3D.z = position3D.z + vitesse3D.y* temps;
		vitesse3D.x = vitesse3D.x * 0.7 + accumForce3D.x * temps;

		//vitesse3D.y = vitesse3D.y * 0.7 - 9.81*temps + accumForce3D.y * temps;
		vitesse3D.y = vitesse3D.y * 0.7 + accumForce3D.y * temps;

		vitesse3D.z = vitesse3D.z * 0.7 + accumForce3D.z * temps;
	}
	else if(dimension == 2)
	{
		position2D.x = position2D.x + vitesse2D.x * temps;
		position2D.y = position2D.y + vitesse2D.y* temps;
		vitesse2D.x = vitesse2D.x * 0.7 + accumForce2D.x * temps;

		//vitesse2D.y = vitesse2D.y * 0.7 - 9.81*temps + accumForce2D.y * temps;
		vitesse2D.y = vitesse2D.y * 0.7 + accumForce2D.y * temps;
	}
	
}

void particule::addForce(const vecteur3D &force)
{
	accumForce3D.x += force.x;
	accumForce3D.y += force.y;
	accumForce3D.z += force.z;
}

void particule::addForce(const vecteur2D &force)
{
	accumForce3D.x += force.x;
	accumForce3D.y += force.y;
}

void particule::clearAccum()
{
	accumForce3D.x = 0;
	accumForce3D.y = 0;
	accumForce3D.z = 0;
	accumForce2D.x = 0;
	accumForce2D.y = 0;
}

float particule::distance(const particule &particule)
{
	return sqrt((position3D.x - particule.position3D.x)*(position3D.x - particule.position3D.x) + (position3D.y - particule.position3D.y)*(position3D.y - position3D.y));
}