#pragma once
#include "vecteur3D.h"
#include "Quaternion.h"
#include "math.h"
#include "DragGenerator.h"

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
	Matrice3 transformMatrice;
	Matrice3 inverseInertieTensor;
	vecteur3D forceAccum;
	vecteur3D torqueAccum;
	//DragGenerator dragGenerator;

	RigidBody(vecteur3D position, vecteur3D velocity, vecteur3D orientation);

	Matrice3 calculDonneesDerivees();
	void addForceAtPoint(vecteur3D force, vecteur3D point);
	void addForceAtBodyPoint(vecteur3D force, vecteur3D point);
	void Integrer(float duree);
	void clearAccumulators();
	void updatePosition(float duree);
	void updateOrientation(float duree);
	float getMass() { return 1 / inverseMass; }
};

