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
	int dim = particule.dimension;
	double deltax = dim == 3 ? particule.position3D.x - autreparticule.position3D.x : particule.position2D.x - autreparticule.position2D.x;
	double deltay = dim == 3 ?  particule.position3D.y - autreparticule.position3D.y : particule.position2D.y - autreparticule.position2D.y;
	double deltaz;
	if(dim == 3)
		 deltaz = particule.position3D.z - autreparticule.position3D.z;
	//double vectunitaired = sqrt(x*x+y*y+z*z);
	
	//const vecteur &force= vecteur(-k*(sqrt(deltax*deltax)-L0), -k*(sqrt(deltay*deltay) - L0), -k*(sqrt(deltaz*deltaz) - L0));
	//particule.addForce(force);
}
