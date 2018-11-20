#include "stdafx.h"
#include "RigidBody.h"


RigidBody::RigidBody()
{
}

Matrice3 RigidBody::calculDonneesDerivees()
{
	// Calcul transformMatrice
}
void RigidBody::addForceAtPoint(vecteur3D force, vecteur3D point)
{
	//Convertir point en coordonnées relatives au centre de masse
	// ajouter force à forceAccum
	// ajouter point x Force à TorqueAccum
}

void RigidBody::addForceAtBodyPoint(vecteur3D force, vecteur3D point)
{
	//Convertir point vers le repère du monde
	addForceAtPoint(force, point);
}

void RigidBody::Integrer(float duree)
{
	//Calculer l'accélération linéaire à partir de ForceAccum
	//Calculer l'accélération angulaire à partir de TorqueAccum
	//Update velocité linéaire
	//Update velocité angulaire
	//Ajouter le drag aux deux vélocités
	//Update position
	//Update orientation
	//Calculer les "derived data" // Transform matrix et I-1
	//Clear accumulator
}