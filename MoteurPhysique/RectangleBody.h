#pragma once
#include "vecteur3D.h"
#include "RigidBody.h"
#include"DragGenerator.h"
#include"Sphere.h"

class RectangleBody : public RigidBody
{
public:
	vecteur3D dimensions;
	vecteur3D position;
	RectangleBody();
	RectangleBody(vecteur3D position, vecteur3D velocity, vecteur3D rotation, float linearDamping, float angularDamping, vecteur3D dim);
	virtual Matrice3 getInertieTensor() override;
};

