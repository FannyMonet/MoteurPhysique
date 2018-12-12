#pragma once
#include "particule.h"
#include "RegistreForce.h"
#include "ParticuleContactResolver.h"
#include "GeneratorForceGravite.h"
#include "DragGenerator.h"
#include "RectangleBody.h"
#include "RigidBody.h"
#include "Octree.h"
#include "CollisionData.h"
#include "Primitive.h"

class GameWorld
{
public:
	vector<particule> listParticules;
	vector<RectangleBody> listRectangles;
	RegistreForce registre;
	ParticuleContactResolver resolver;
	GeneratorForceGravite graviteGenerator;
	DragGenerator dragGenerator;
	Octree octree;
	CollisionData collisionData;
	GameWorld();

	void update(float rate);
	void integrer(float rate);
	void generateContacts(Primitive prim1, Primitive prim2, CollisionData * data);
};

