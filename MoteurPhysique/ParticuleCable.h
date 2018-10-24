#pragma once
#include "ParticuleLink.h"

class ParticuleCable : ParticuleLink
{
public:

	float restitution;
	float maxLength;

	ParticuleCable();

	float currentLength();
	void ajouterContact();
};

