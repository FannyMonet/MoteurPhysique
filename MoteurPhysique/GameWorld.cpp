#include "stdafx.h"
#include "GameWorld.h"

using namespace std;

GameWorld::GameWorld()
{
	listParticules.emplace_back(5, 2, 10, 300, 200, 20, 1, 0.7f, 2, 1);
	listParticules.emplace_back(30, 40, 5, 0, 40, 0, 2, 0.7f, 4, 1);
	listParticules.emplace_back(10, 30, 6, 30, 25, 30, 3, 0.7f, 6, 1);
	registre = RegistreForce();
	resolver = ParticuleContactResolver();
	graviteGenerator = GeneratorForceGravite();
	dragGenerator = DragGenerator(0.2, 0.3);
	rectangle = RectangleBody(vecteur3D(0,0,0), vecteur3D(0, 0, 1), vecteur3D(0, 1, 0),0.1,0.1, vecteur3D(0, 0, 0), vecteur3D(0, 0, 0) );
}

void GameWorld::update(float rate)
{
	listParticules = resolver.resolveContacts(listParticules);
	integrer(rate);
}

void GameWorld::integrer(float rate)
{

	dragGenerator.updateforceparticule(&listParticules[0], rate);
	for (int i = 0; i < listParticules.size(); i++)
	{
		graviteGenerator.updateforceparticule(&listParticules[i], rate);
		listParticules[i].Integrer(rate);
		listParticules[i].clearAccum();
	}
}