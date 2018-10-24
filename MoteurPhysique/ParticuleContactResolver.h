#pragma once
#include "ParticuleContact.h"

class ParticuleContactResolver
{
public:

	vector<ParticuleContact> listCollisions;
	float duree;
	ParticuleContactResolver();

	void resolveContacts(int iterationsUsed, float duree, int nbCollisions, int nbIterationsMax);
};

