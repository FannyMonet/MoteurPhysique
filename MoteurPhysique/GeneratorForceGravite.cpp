#include "stdafx.h"
#include "GeneratorForceGravite.h"


GeneratorForceGravite::GeneratorForceGravite()
{
	gravite3D = vecteur3D(0,-9.81,0);
	gravite2D = vecteur2D(0, -9.81);
}

void GeneratorForceGravite::updateforceparticule(particule particule, float duration)
{
	/*int dim = particule.dimension;
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
	}*/
}


