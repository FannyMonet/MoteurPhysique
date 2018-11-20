#include "stdafx.h"
#include "GeneratorForceGravite.h"

using namespace std;

GeneratorForceGravite::GeneratorForceGravite()
{
	gravite3D = vecteur3D(0,-9.81,0);
	gravite2D = vecteur2D(0, -9.81);
}

void GeneratorForceGravite::updateforceparticule(particule* particule, float duration)
{

	int dim = particule->dimension;
	if (dim == 2)
	{
		particule->addForce(gravite2D);
	}
	if (dim == 3)
	{
		
		particule->addForce(vecteur3D(gravite3D.x, gravite3D.y * particule->masse, gravite3D.z));
	}
}


