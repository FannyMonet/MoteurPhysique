#pragma once
#include "Particuleforcegenerator.h"

class ParticuleSpring :
	public Particuleforcegenerator
{
public:
	
	particule autreparticule;
	int k=0;
	double L0=0;
	ParticuleSpring(particule Vautreparticule, int Vk, double VL0)
	{
		k = Vk;
		L0 = VL0;
		autreparticule = Vautreparticule;
	}

	

	virtual void updateforceparticule(particule particule, float duration);

};

