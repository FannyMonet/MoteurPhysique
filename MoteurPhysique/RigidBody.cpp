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
	//Convertir point en coordonn�es relatives au centre de masse
	// ajouter force � forceAccum
	// ajouter point x Force � TorqueAccum
}

void RigidBody::addForceAtBodyPoint(vecteur3D force, vecteur3D point)
{
	//Convertir point vers le rep�re du monde
	addForceAtPoint(force, point);
}

void RigidBody::Integrer(float duree)
{
	//Calculer l'acc�l�ration lin�aire � partir de ForceAccum
	//Calculer l'acc�l�ration angulaire � partir de TorqueAccum
	//Update velocit� lin�aire
	//Update velocit� angulaire
	//Ajouter le drag aux deux v�locit�s
	//Update position
	//Update orientation
	//Calculer les "derived data" // Transform matrix et I-1
	//Clear accumulator
}