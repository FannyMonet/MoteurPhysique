#include "stdafx.h"
#include "ParticuleContactResolver.h"


ParticuleContactResolver::ParticuleContactResolver()
{
}

//Fonction récursive parcourant toutes les collisions listées dans listCollisions et les résolvant, jusqu'à 
// un maximum d'itéractions 
void ParticuleContactResolver::resolveContacts(int iterationsUsed, float duree, int nbCollisions, int nbIterationsMax)
{
	nbCollisions = listCollisions.size();
	nbIterationsMax = nbCollisions * 2;
	
	for (int i = 0; i < nbCollisions; i++)
	{
		if (iterationsUsed == nbIterationsMax)
			return;
		int vs = listCollisions[i].calculerVs();
		if (vs >= 0)
			return;
		listCollisions[i].resolve(duree);
		iterationsUsed++;
	}
	resolveContacts(iterationsUsed, duree, nbCollisions, nbIterationsMax);
}
