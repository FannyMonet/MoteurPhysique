#include "stdafx.h"
#include "Particuleforcegenerator.h"


Particuleforcegenerator::Particuleforcegenerator()
{
}

void Particuleforcegenerator::updateforceparticule(particule * particule, float duration)
{
	particule->Integrer(duration);
}



