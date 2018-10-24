#include "stdafx.h"
#include "ParticuleCable.h"


ParticuleCable::ParticuleCable()
{
}
ParticuleCable::ParticuleCable(particule *p1, particule *p2, float mLength, float r)
{
	particules[0] = p1;
	particules[1] = p2;
	maxLength = mLength;
	restitution = r;
}
float ParticuleCable::currentLength()
{
	particule *p1 = particules[0];
	particule *p2 = particules[1];

	vecteur3D pos1 = p1->position3D;
	vecteur3D pos2 = p2->position3D;

	vecteur3D opposePos2 = pos2.Multiplication_Scalaire(-1);
	vecteur3D diff = pos1.Addition(opposePos2);

	return diff.Norme();
}

void ParticuleCable::ajouterContact()
{
	if (currentLength() >= maxLength)
	{
		ParticuleContact contact = ParticuleContact(particules[0], particules[1], restitution, 0.7);
	}
}