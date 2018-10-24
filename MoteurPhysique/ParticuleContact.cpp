#include "stdafx.h"
#include "ParticuleContact.h"


ParticuleContact::ParticuleContact()
{

}
ParticuleContact::ParticuleContact(particule *p1, particule *p2, float Vrestitution, float Vpenetration)
{
	particules[0] = p1;
	particules[1] = p2;
	restitution = Vrestitution;
	penetration = Vpenetration;
}


void ParticuleContact::resolve(float duree)
{
	resolveVelocity(duree);
	resolveInterpenetration();
}
float ParticuleContact::calculerVs()
{
	particule *p1 = particules[0];
	particule *p2 = particules[1];

	vecteur3D velocity1 = p1->vitesse3D;
	vecteur3D velocity2 = p2->vitesse3D;

	vecteur3D v2 = velocity2.Multiplication_Scalaire(-1);
	vecteur3D diff = velocity1.Addition(v2);
	contactNormal = diff;
	float vs = diff.Produit_Scalaire(diff);
	return vs;
}
void ParticuleContact::resolveVelocity(float duree)
{
	float vs = calculerVs();
	float cvs = vs * (-restitution);

	particule *p1 = particules[0];
	particule *p2 = particules[1];

	p1->vitesse3D = vecteur3D(p1->vitesse3D.x * cvs, p1->vitesse3D.y * cvs, p1->vitesse3D.z * cvs);
	p2->vitesse3D = vecteur3D(p2->vitesse3D.x * cvs, p2->vitesse3D.y * cvs, p2->vitesse3D.z * cvs);

	p1->Integrer(duree);
	p2->Integrer(duree);
}

void ParticuleContact::resolveInterpenetration()
{
	particule *p1 = particules[0];
	particule *p2 = particules[1];

	float deltaP1 = p2->masse / (p1->masse + p2->masse) * penetration;
	float deltaP2 = - p1->masse / (p1->masse + p2->masse)* penetration;

	vecteur3D vP1 = contactNormal.Multiplication_Scalaire(deltaP1);
	vecteur3D vP2 = contactNormal.Multiplication_Scalaire(deltaP2);

	p1->vitesse3D.Addition(vP1);
	p2->vitesse3D.Addition(vP2);
}
