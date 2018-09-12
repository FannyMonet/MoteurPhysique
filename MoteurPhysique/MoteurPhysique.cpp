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
	float tmps = (float) 1/30;
	while (estnull == false)
	{
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli > elapsed_seconds = end - start;
		
		vecteur1.Integrer(tmps);
		vecteur2.Integrer(tmps);
		vecteur3.Integrer(tmps);
		cout << "la position de la particule 1 est : x = " << vecteur1.x << " / y = " << vecteur1.y << " / z =" << vecteur1.z << " metre / temps= "<< tmps << " seconde" << endl;
		cout << "la position de la particule 2 est : x = " << vecteur2.x << " / y = " << vecteur2.y << " / z =" << vecteur2.z << " metre / temps= " << tmps << " seconde" << endl;
		cout << "la position de la particule 3 est : x = " << vecteur3.x << " / y = " << vecteur3.y << " / z =" << vecteur3.z << " metre / temps= " << tmps << " seconde" << endl;
		if (vecteur1.z < 0)
		{
			if (vecteur2.z < 0)
			{
				if (vecteur3.z < 0)
				{
				estnull = true;
				}
			}		
		
		}
		tmps += (float) 1/30 ;
	}
	system("PAUSE");
}