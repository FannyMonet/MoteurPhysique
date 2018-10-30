#include "stdafx.h"
#include "GameWorld.h"


GameWorld::GameWorld()
{
	listParticules.emplace_back(5, 5, 5, 10, 50, 20, 1, 0.7f, 4, 5);
	listParticules.emplace_back(5, 5, 5, 0, 40, 0, 2, 0.7f, 4, 5);
	listParticules.emplace_back(5, 5, 5, 3, 25, 30, 3, 0.7f, 4, 5);
	registre = RegistreForce();
	resolver = ParticuleContactResolver();
	graviteGenerator = GeneratorForceGravite();
}

void GameWorld::update(float rate)
{
	listParticules = resolver.resolveContacts(listParticules);
	integrer(rate);
}

void GameWorld::integrer(float rate)
{
	for (int i = 0; i < listParticules.size(); i++)
	{
		graviteGenerator.updateforceparticule(&listParticules[i], rate);
		listParticules[i].Integrer(rate);
		listParticules[i].clearAccum();
	}
}