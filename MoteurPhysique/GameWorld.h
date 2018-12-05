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
	vector<RectangleBody> listRectangles;
	RegistreForce registre;
	ParticuleContactResolver resolver;
	GeneratorForceGravite graviteGenerator;
	DragGenerator dragGenerator;
	GameWorld();

	void update(float rate);
	void integrer(float rate);
};

