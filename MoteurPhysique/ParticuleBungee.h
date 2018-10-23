#pragma once
#include "Particuleforcegenerator.h"
class ParticuleBungee :
	public Particuleforcegenerator
{
public:
	ParticuleBungee(particule Vautreparticule, int Vk, double VL0)
	{
		autreparticule = Vautreparticule;
		k = Vk;
		L0 = VL0;
	}

	particule autreparticule;
	int k = 0;
	double L0 = 0;



	virtual void updateforceparticule(particule particule, float duration);


};

