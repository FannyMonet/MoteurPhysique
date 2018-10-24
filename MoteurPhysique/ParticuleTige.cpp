#include "stdafx.h"
#include "ParticuleTige.h"


ParticuleTige::ParticuleTige()
{
}

ParticuleTige::ParticuleTige(particule *p1, particule *p2, float l)
{
	longueur = l;
	particules[0] = p1;
	particules[1] = p2;
}


void ParticuleTige::ajouterContact()
{
	particule *p1 = particules[0];
	particule *p2 = particules[1];
	//On crée une nouvelle collision entre p1 et p2 avec un coefficient de restitution = 0
	ParticuleContact contact = ParticuleContact(p1, p2, 0, 0.7);
}
