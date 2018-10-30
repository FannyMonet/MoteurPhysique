#pragma once
#include "stdafx.h"
#include <vector>
#include "vecteur.h"
#include "particule.h"
#include "Particuleforcegenerator.h"

using namespace std;

class RegistreForce
{
public:
	struct EnregistrementForce
	{
		particule * particule;
		Particuleforcegenerator * Fg;
	}alpha;
	typedef std::vector<EnregistrementForce> Registre;

	Registre registre;


	void AddEntity(particule * particule, Particuleforcegenerator * Fg);

	void DeleteEntity(particule * particule, Particuleforcegenerator * Fg);

	void UpdateEntity(double duration);
};

