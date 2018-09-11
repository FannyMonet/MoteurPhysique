#include <iostream>
#include <vector>
#include "particule.h"
#include "vecteur.h"


int particule::Inverse_Masse(int Masse)
{
	int Inverse_Masse = 1/Masse;
	return Inverse_Masse;
}

void particule::Integrer(float temps)
{
	position = Addition(Position ,Multiplication_Scalaire(Vitesse, temps,3),3);
	vitesse = Addition(Multiplication_Scalaire(Vitesse ,Dumping) ,Multiplication_Scalaire(Acceleration, temps));
}