#include "stdafx.h"
#include "ParticuleContactResolver.h"

using namespace std;

ParticuleContactResolver::ParticuleContactResolver()
{
}

//Fonction parcourant toutes les collisions listées dans listCollisions et les résolvant, jusqu'à 
// un maximum d'itéractions 
vector<particule> ParticuleContactResolver::resolveContacts(vector<particule>listParticules)
{
	
	int nbCollisions = listCollisions.size();
	int nbIterationsMax = nbCollisions * 2;
	ParticuleContact contact;
	int index = 0;
	for (int i = 0; i < nbIterationsMax; i++)
	{
		detectContact(listParticules);
		index = indexMinVs(listCollisions);
		contact = listCollisions[index];
		int vsMin = contact.calculerVs();
		if (vsMin >= 0)
			return listParticules;
		contact.resolve(duree);
		listCollisions.erase(listCollisions.begin() + index);
	}
	return listParticules;
}

int ParticuleContactResolver::indexMinVs(vector<ParticuleContact> listCollisions)
{
	float min = listCollisions[0].calculerVs();
	int index = 0;
	for (int i = 0; i < listCollisions.size(); i++)
	{
		if (listCollisions[i].calculerVs() < min)
			index = i;
	}
	return index;
}

void ParticuleContactResolver::detectContact(vector<particule>listParticules)
{
	ParticuleContact contact;
	for (int i = 0; i < listParticules.size(); i++)
	{
		for (int j = 0; j < listParticules.size(); j++)
		{
			float distance = listParticules[i].distance(listParticules[j]);
			if (distance < listParticules[i].rayon + listParticules[j].rayon)
			{
				contact = ParticuleContact(&listParticules[i], &listParticules[j], 0.7, 0.7);
				listCollisions.emplace_back(contact);
			}
		}
	}
}