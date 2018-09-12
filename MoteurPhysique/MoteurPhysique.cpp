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
	particule p = particule(5, 5, 5, 0.08, 0, 0);
	
	cout << "la position de la particule est : x =";
	bool estnull = false;
	auto start = std::chrono::system_clock::now();
	while (estnull == false)
	{
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli > elapsed_seconds = end - start;
		double tmps = elapsed_seconds.count() / 30;
		p.Integrer(tmps);
		cout << "la position de la particule est : x =" << p.x << "y = " << p.y << "z =" << p.z << " metre" << endl;
		if (0 < p.y < 1)
		{
			estnull = true;
		}
	}
	system("PAUSE");
}