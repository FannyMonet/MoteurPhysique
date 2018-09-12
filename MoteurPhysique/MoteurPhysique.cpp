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
	particule p = particule(5, 5, 5, 0, 5, 0);
	
	cout << "la position de la particule est : x =";
	bool estnull = false;
	auto start = std::chrono::system_clock::now();
	float tmps = 0.0333333333333333333333333333333333333 ;
	while (estnull == false)
	{
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli > elapsed_seconds = end - start;
		//double tmps = 1 / 30;
		p.Integrer(tmps);
		cout << "la position de la particule est : x = " << p.x << " / y = " << p.y << " / z =" << p.z << " / temps= "<< tmps << " metre" << endl;
		if (p.z < 0)
		{
			estnull = true;
			
		}
		tmps += 0.033333333333333333333333333333333333333 ;
	}
	system("PAUSE");
}