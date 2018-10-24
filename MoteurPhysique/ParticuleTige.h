#pragma once
#include "ParticuleLink.h"
class ParticuleTige : ParticuleLink
{
public:

	float longueur; //longueur de la tige

	ParticuleTige();
	ParticuleTige(particule *p1, particule *p2, float l);

	void ajouterContact();
};

