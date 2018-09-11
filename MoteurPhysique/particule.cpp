#include "stdafx.h"
#include <iostream>
#include <vector>
#include "particule.h"
#include "vecteur.cpp"


int particule::Inverse_Masse(int Masse)
{
	int Inverse_Masse = 1/Masse;
	return Inverse_Masse;
}

void particule::Integrer(float temps)
{
	Position = (Addition(Position , Multiplication_Scalaire(Vitesse, temps,3),3),3);
	Vitesse = Addition(Multiplication_Scalaire(Vitesse ,Dumping) ,Multiplication_Scalaire(Acceleration, temps));
}