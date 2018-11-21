#pragma once
#include "particule.h"
#include "RegistreForce.h"
#include "ParticuleContactResolver.h"
#include "GeneratorForceGravite.h"
#include "DragGenerator.h"
#include "RectangleBody.h"
#include "RigidBody.h"

class GameWorld
{
public:
	vector<particule> listParticules;
	RegistreForce registre;
	ParticuleContactResolver resolver;
	GeneratorForceGravite graviteGenerator;
	DragGenerator dragGenerator;
	RigidBody rectangle;

	GameWorld();

	void update(float rate);
	void integrer(float rate);
};

