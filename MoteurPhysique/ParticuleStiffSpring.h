#pragma once
#include "Particuleforcegenerator.h"
class ParticuleStiffSpring :
	public Particuleforcegenerator
{
public:
	ParticuleStiffSpring(vecteur3D Vancrage, float Vconstanteelastique, float Vdamping)
	{
		ancrage = Vancrage;
	 constanteelastique=Vconstanteelastique;
	damping=Vdamping;

	}
	vecteur3D ancrage;
	float constanteelastique;
	float damping;

	virtual void updateforceparticule(particule particule, float duration);
};

