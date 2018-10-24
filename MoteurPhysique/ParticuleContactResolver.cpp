#include "stdafx.h"
#include "ParticuleContactResolver.h"


ParticuleContactResolver::ParticuleContactResolver()
{
}

//Fonction r�cursive parcourant toutes les collisions list�es dans listCollisions et les r�solvant, jusqu'� 
// un maximum d'it�ractions 
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
