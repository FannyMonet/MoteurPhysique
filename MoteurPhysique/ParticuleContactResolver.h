#pragma once
#include "ParticuleContact.h"
#include "particule.h"
class ParticuleContactResolver
{
public:

	vector<ParticuleContact> listCollisions;
	float duree;
	ParticuleContactResolver();

	vector<particule> resolveContacts(vector<particule>listParticules);
	void detectContact(vector<particule>listParticules);
	int indexMinVs(vector<ParticuleContact> listCollisions);
};

