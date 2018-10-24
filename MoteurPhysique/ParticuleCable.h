#pragma once
#include "ParticuleLink.h"

class ParticuleCable : ParticuleLink
{
public:

	float restitution;
	float maxLength;

	ParticuleCable();
	ParticuleCable(particule *p1, particule *p2, float maxLength, float restitution);

	float currentLength();
	void ajouterContact();
};

