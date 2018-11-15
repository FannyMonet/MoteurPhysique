#pragma once
#include "ParticuleContact.h"
#include "particule.h"

class ParticuleContactResolver
{
public:

	std::vector<ParticuleContact> listCollisions;
	float duree;
	ParticuleContactResolver();

	std::vector<particule> resolveContacts(std::vector<particule>listParticules);
	void detectContact(std::vector<particule>listParticules);
	int indexMinVs(std::vector<ParticuleContact> listCollisions);
};

