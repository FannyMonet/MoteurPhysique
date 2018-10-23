#include "stdafx.h"
#include "ParticuleAnchoredSpring.h"


ParticuleAnchoredSpring::ParticuleAnchoredSpring()
{
}


ParticuleAnchoredSpring::~ParticuleAnchoredSpring()
{
}

void ParticuleAnchoredSpring::updateforceparticule(particule particule, float duration)
{
	//int force;

	double deltax = particule.position.x - pointancrage.x;
	double deltay = particule.position.y - pointancrage.y;
	double deltaz = particule.position.z - pointancrage.z;
	//double vectunitaired = sqrt(x*x+y*y+z*z);

	const vecteur &force = vecteur(-k*(sqrt(deltax*deltax) - L0), -k*(sqrt(deltay*deltay) - L0), -k*(sqrt(deltaz*deltaz) - L0));
	particule.addForce(force);
}
