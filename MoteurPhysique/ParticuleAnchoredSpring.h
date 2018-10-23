#pragma once
#include "Particuleforcegenerator.h"
#include "vecteur.h"
using namespace std;
class ParticuleAnchoredSpring :
	public Particuleforcegenerator
{
public:
	ParticuleAnchoredSpring();
	~ParticuleAnchoredSpring();
	vecteur pointancrage = vecteur();
	particule autreparticule = particule();
	int k = 0;
	double L0 = 0;

	virtual void updateforceparticule(particule particule, float duration);

};


