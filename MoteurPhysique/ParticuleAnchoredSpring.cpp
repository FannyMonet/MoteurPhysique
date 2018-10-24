#include "stdafx.h"
#include "ParticuleAnchoredSpring.h"





void ParticuleAnchoredSpring::updateforceparticule(particule particule, float duration)
{
	//int force;
	int dim = particule.dimension;
	double deltax = dim == 3 ? particule.position3D.x - pointancrage3D.x : particule.position2D.x - pointancrage2D.x;
	double deltay = dim == 3 ? particule.position3D.y - pointancrage3D.y : particule.position2D.y - pointancrage2D.y;
	double deltaz;
	
		


	vector<int> force;


	if (dim == 2)
	{
		const  vecteur2D forceCst(-k*(sqrt(deltax*deltax) - L0), -k*(sqrt(deltay*deltay) - L0));
		particule.addForce(forceCst);
	}
	if (dim == 3)
	{
		deltaz = particule.position3D.z - pointancrage3D.z;
		const  vecteur3D forceCst(-k*(sqrt(deltax*deltax) - L0), -k*(sqrt(deltay*deltay) - L0), -k*(sqrt(deltaz*deltaz) - L0));
		particule.addForce(forceCst);
	}



}
