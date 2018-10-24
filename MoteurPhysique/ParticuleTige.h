#pragma once
#include "ParticuleLink.h"
class ParticuleTige : ParticuleLink
{
public:

	//particule *particules[2];
	float longueur; //longueur de la tige

	ParticuleTige();

	void ajouterContact();
};

