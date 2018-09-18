// MoteurPhysique.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include "particule.h"
#include "MoteurPhysique.h"
#include "chrono"
using namespace std;

int main(int argc, char* argv[]) 
{
	particule vecteur1 = particule(5, 5, 5, 0, 5, 0);
	particule vecteur2 = particule(5, 5, 5, 0, 4, 0);
	particule vecteur3 = particule(5, 5, 5, 0, 3, 0);
	
	int estnull = 0;
	auto start = std::chrono::system_clock::now();
	float rate = (float) 1/30;
	float tempsTotal = 0;
	while (estnull == false)
	{	
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli > elapsed_seconds = end - start;
		
		vecteur1.Integrer(rate);
		vecteur2.Integrer(rate);
		vecteur3.Integrer(rate);
		cout << "la position de la particule 1 est : x = " << vecteur1.position.x << " / y = " << vecteur1.position.y << " / z =" << vecteur1.position.z << " metre / temps= "<< tempsTotal << " seconde" << endl;
		cout << "la position de la particule 2 est : x = " << vecteur2.position.x << " / y = " << vecteur2.position.y << " / z =" << vecteur2.position.z << " metre / temps= " << tempsTotal << " seconde" << endl;
		cout << "la position de la particule 3 est : x = " << vecteur3.position.x << " / y = " << vecteur3.position.y << " / z =" << vecteur3.position.z << " metre / temps= " << tempsTotal << " seconde" << endl;
		if (vecteur1.position.z < 0 && vecteur2.position.z < 0 && vecteur3.position.z < 0)
			estnull = true;
		tempsTotal += (float) 1/30 ;
	}
	system("PAUSE");
}