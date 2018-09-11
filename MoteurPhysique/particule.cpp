#include "stdafx.h"
#include "vecteur.h"
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
	vecteur test =  vecteur(x,y,z);
	int position[3] = test.Addition(Position, vecteur::Multiplication_Scalaire(Vitesse, temps, 3), 3);
	vitesse = Addition(Multiplication_Scalaire(Vitesse ,Dumping) ,Multiplication_Scalaire(Acceleration, temps));
}