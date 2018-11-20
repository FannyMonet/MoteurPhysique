#include "stdafx.h"
#include "ParticuleLink.h"

ParticuleLink::ParticuleLink()
{
	
}

ParticuleLink::ParticuleLink(particule *p1, particule *p2)
{
	particules[0] = p1;
	particules[1] = p2;
}

void ParticuleLink::ajouterContact()
{

}

float ParticuleLink::currentLength()
{
	return 0;
}