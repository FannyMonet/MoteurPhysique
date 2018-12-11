#pragma once
#include "vecteur3D.h"
#include "Quaternion.h"
#include "math.h"
#include "DragGenerator.h"
#include <iostream>

class RigidBody
{
public:
	float inverseMass;
	float linearDamping;
	float angularDamping;
	vecteur3D position;
	vecteur3D velocity;
	Quaternion orientation;
	vecteur3D rotation;
	Matrice4 transformMatrice;
	Matrice3 inverseInertieTensor;
	vecteur3D forceAccum;
	vecteur3D torqueAccum;
	DragGenerator dragGenerator;
	vecteur3D* points;

	RigidBody();
	RigidBody(vecteur3D position, vecteur3D velocity, vecteur3D rotation, float linearDamping, float angularDamping);

	virtual void calculDonneesDerivees();
	virtual void addForceAtPoint(vecteur3D force, vecteur3D point);
	virtual void addForceAtBodyPoint(vecteur3D force, vecteur3D point);
	virtual void Integrer(float duree);
	virtual void clearAccumulators();
	virtual void updatePosition(float duree);
	virtual void updateOrientation(float duree);
	virtual float getMass() { return 1 / inverseMass; }
	virtual Matrice3 getInertieTensor() { return Matrice3(); };
};

