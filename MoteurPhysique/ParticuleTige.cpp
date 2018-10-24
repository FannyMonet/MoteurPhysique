#include "stdafx.h"
#include "ParticuleTige.h"


ParticuleTige::ParticuleTige()
{
}

void ParticuleTige::ajouterContact()
{
	particule *p1 = particules[0];
	particule *p2 = particules[1];
	ParticuleContact contact = ParticuleContact(p1, p2, 0, 0.7);
}
