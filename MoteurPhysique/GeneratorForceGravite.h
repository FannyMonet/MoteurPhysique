#pragma once
#include "Particuleforcegenerator.h"
#include "vecteur3D.h"
class GeneratorForceGravite :
	public Particuleforcegenerator
{
public:
	


	GeneratorForceGravite();
	vecteur3D gravite3D;
	vecteur2D gravite2D;
	virtual void updateforceparticule(particule particule, float duration);
};

