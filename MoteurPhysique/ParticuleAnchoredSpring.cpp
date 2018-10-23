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
	
	double deltax = particule.dimension == 3 ? particule.position3D.x - pointancrage3D.x : particule.position2D.x - pointancrage2D.x;
	double deltay = particule.dimension == 3 ? particule.position3D.y - pointancrage3D.y : particule.position2D.y - pointancrage2D.y;
	double deltaz;
	if(particule.dimension == 3)
		deltaz = particule.position3D.z - pointancrage3D.z;
	//double vectunitaired = sqrt(x*x+y*y+z*z);

	//const vecteur &force = vecteur(-k*(sqrt(deltax*deltax) - L0), -k*(sqrt(deltay*deltay) - L0), -k*(sqrt(deltaz*deltaz) - L0));
	//particule.addForce(force);
}
