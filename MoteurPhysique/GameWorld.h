#pragma once
#include "particule.h"
#include "RegistreForce.h"
#include "ParticuleContactResolver.h"
#include "GeneratorForceGravite.h"

class GameWorld
{
public:
	vector<particule> listParticules;
	RegistreForce registre;
	ParticuleContactResolver resolver;
	GeneratorForceGravite graviteGenerator;

	GameWorld();

	void update(float rate);
	void integrer(float rate);
};

