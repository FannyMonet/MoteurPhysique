// MoteurPhysique.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "particule.h"
#include "MoteurPhysique.h"
using namespace std;

int main(int argc, char* argv[]) 
{
	particule p = particule(0, 0, 0, 8, 0, 0);
	cout << p.vitesse.vec[0];
	system("PAUSE");
}