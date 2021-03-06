#include "stdafx.h"
#include "ParticuleBungee.h"

using namespace std;

void ParticuleBungee::updateforceparticule(particule particule, float duration)
{
	if (sqrt(autreparticule.position3D.x*autreparticule.position3D.x + autreparticule.position3D.y*autreparticule.position3D.y + autreparticule.position3D.z*autreparticule.position3D.z) >= L0)
	{
		int dim = particule.dimension;
		double deltax = dim == 3 ? particule.position3D.x - autreparticule.position3D.x : particule.position2D.x - autreparticule.position2D.x;
		double deltay = dim == 3 ? particule.position3D.y - autreparticule.position3D.y : particule.position2D.y - autreparticule.position2D.y;
		double deltaz;
		if (dim == 3)
			deltaz = particule.position3D.z - autreparticule.position3D.z;

		if (dim == 2)
		{
			const  vecteur2D forceCst(-k*(sqrt(deltax*deltax) - L0), -k*(sqrt(deltay*deltay) - L0));
			particule.addForce(forceCst);
		}
		if (dim == 3)
		{
			const  vecteur3D forceCst(-k*(sqrt(deltax*deltax) - L0), -k*(sqrt(deltay*deltay) - L0), -k*(sqrt(deltaz*deltaz) - L0));
			particule.addForce(forceCst);
		}
	}
}
