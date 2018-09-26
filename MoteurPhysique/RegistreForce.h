#pragma once
#include "stdafx.h"
#include <vector>
#include "vecteur.h"
#include "particule.h"
#include "Particuleforcegenerator.h"

using namespace std;

class RegistresForces
{
	struct EnregistrementForce
	{
		particule * particule;
		Particuleforcegenerator * Fg;
	};
	typedef std::vector<EnregistrementForce> Registre;

};
