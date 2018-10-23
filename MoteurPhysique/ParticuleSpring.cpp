#include "stdafx.h"
#include "ParticuleSpring.h"


ParticuleSpring::ParticuleSpring()
{
	k = 0;
	L0 = 0;
}


ParticuleSpring::~ParticuleSpring()
{
}

void ParticuleSpring::updateforceparticule(particule  particule, float duration)
{
	//int force;

	double deltax = particule.position.x - autreparticule.position.x;
	double deltay = particule.position.y - autreparticule.position.y;
	double deltaz = particule.position.z - autreparticule.position.z;
	//double vectunitaired = sqrt(x*x+y*y+z*z);
	
	const vecteur &force= vecteur(-k*(sqrt(deltax*deltax)-L0), -k*(sqrt(deltay*deltay) - L0), -k*(sqrt(deltaz*deltaz) - L0));
	particule.addForce(force);
}
