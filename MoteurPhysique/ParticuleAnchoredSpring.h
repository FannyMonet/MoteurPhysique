#pragma once
#include "Particuleforcegenerator.h"

class ParticuleAnchoredSpring :
	public Particuleforcegenerator
{
public:

	vecteur2D pointancrage2D;
	vecteur3D pointancrage3D;
	int k = 0;
	double L0 = 0;
	ParticuleAnchoredSpring(vecteur3D Vpointancrage3D, int Vk, double VL0)
	{
		k = Vk;
		L0 = VL0;
		pointancrage3D = Vpointancrage3D;
	};

	ParticuleAnchoredSpring(vecteur2D Vpointancrage2D, int Vk, double VL0)
	{
		k = Vk;
		L0 = VL0;
		pointancrage2D = Vpointancrage2D;
	};

	virtual void updateforceparticule(particule particule, float duration);

};


