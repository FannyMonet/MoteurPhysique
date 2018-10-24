#include "stdafx.h"
#include "ParticuleBouyancy.h"



void ParticuleBouyancy::updateforceparticule(particule particule, float duration)
{
	vecteur3D force(0, 0, 0);
	if (particule.position3D.y <= hauteureau - profmax)
	{
		force.y = volumeobjet * densite;
		particule.addForce(force);
	}
	if (particule.position3D.y >= hauteureau + profmax  && particule.position3D.y <= hauteureau - profmax)
	{
		force.y = volumeobjet * densite*(particule.position3D.y -profmax-hauteureau)/(2*profmax);
		particule.addForce(force);
	}
}
