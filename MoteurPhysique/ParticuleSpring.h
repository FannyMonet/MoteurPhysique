#pragma once
#include "Particuleforcegenerator.h"
#include "vecteur.h"
using namespace std;
class ParticuleSpring :
	public Particuleforcegenerator
{
public:
	ParticuleSpring(particule *autreparticule,int k, double L0);
	~ParticuleSpring(); 
	particule *autreparticule;
	int k=0;
	double L0=0;

	

	virtual void updateforceparticule(particule particule, float duration);

};

