#pragma once
#include "stdafx.h"
#include <vector>
#include "vecteur.h"
#include "particule.h"

using namespace std;

class RegistresForces
{
	struct EnregistrementForce
	{
		Particule * particule;
		ParticuleForceGenerateur * Fg;
	};
	typedef std::vector<EnregistrementForce> Registre;

};
