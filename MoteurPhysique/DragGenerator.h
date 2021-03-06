#pragma once
#include "Particuleforcegenerator.h"

class DragGenerator :
	public Particuleforcegenerator
{
public:
	DragGenerator();
	DragGenerator(float Vk1, float Vk2);
	float K1;
	float K2;
	vecteur3D drag3D;
	vecteur2D drag2D;


	virtual void updateforceparticule(particule* particule, float duration);
	virtual void updateForceRigidBody(vecteur3D velocity, vecteur3D rotation, vecteur3D* forceAccum, vecteur3D* torqueAccum, float duration);
};

