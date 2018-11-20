#include "stdafx.h"
#include "ParticuleContact.h"

using namespace std;

ParticuleContact::ParticuleContact()
{
}

// Constructeur de ParticuleContact
ParticuleContact::ParticuleContact(particule *p1, particule *p2, float Vrestitution, float Vpenetration)
{
	particules[0] = p1;
	particules[1] = p2;
	restitution = Vrestitution;
	penetration = Vpenetration;
}

// Résout le contact entre les deux particules
void ParticuleContact::resolve(float duree)
{
	resolveInterpenetration();
	resolveVelocity(duree);
}
// On calcule la vélocité d'éloignement des particules
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
// A l'aide de vs et du coefficient de restitution, on modifie les vecteurs vitesse des particules et on calcule leurs 
// nouvelles positions et vitesses à la frame suivante.
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
// Avec le coefficient de penetration, on résout l'interpénétration des deux particules
// afin d'éviter qu'elles se chevauchent (dans le cas d'un coefficient de restitution trop faible)
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
