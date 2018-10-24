#pragma once
#include "particule.h"

class ParticuleContact
{
public:
	ParticuleContact();
	ParticuleContact(particule *p1, particule *p2, float Vrestitution, float Vpenetration);

	particule *particules[2];
	float restitution;
	vecteur3D contactNormal;
	float penetration;

	void resolve(float duree);
	float calculerVs();
	void resolveVelocity(float duree);
	void resolveInterpenetration();
};

