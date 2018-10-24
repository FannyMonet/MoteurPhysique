#pragma once
#include "ParticuleContactGenerator.h"
#include "ParticuleContact.h"
#include "particule.h"

class ParticuleLink : ParticuleContactGenerator
{
public:

	particule *particules[2];

	ParticuleLink();
	ParticuleLink(particule *p1, particule *p2);

	virtual void ajouterContact();
	virtual float currentLength();
};

