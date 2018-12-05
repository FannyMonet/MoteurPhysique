#include "stdafx.h"
#include "GameWorld.h"
#include <vector>

using namespace std;

GameWorld::GameWorld()
{
	listRectangles = vector<RigidBody>();
	registre = RegistreForce();
	resolver = ParticuleContactResolver();
	graviteGenerator = GeneratorForceGravite();
	dragGenerator = DragGenerator(0.2, 0.3);
	rectangle = RectangleBody(vecteur3D(100, 5, 10), vecteur3D(1, 10, 0), vecteur3D(0, 1, 0), vecteur3D(0, 0, 0), 0.1, 0.1, vecteur3D(0, 0, 0));
	listRectangles.emplace_back( RectangleBody(vecteur3D(0,0,0), vecteur3D(0, 15, 0), vecteur3D(0, 1, 0), vecteur3D(0, 0, 0), 0.1, 0.1, vecteur3D(0, 0, 0) ));
}

void GameWorld::update(float rate)
{
	//listParticules = resolver.resolveContacts(listParticules);

	integrer(rate);
}

void GameWorld::integrer(float rate)
{
	for (int i = 0; i < listRectangles.size(); i++)
	{
		//graviteGenerator.updateforceparticule(&listParticules[i], rate);
		listRectangles[i].Integrer(rate);
	}
	//dragGenerator.updateforceparticule(&listParticules[0], rate);
	/*for (int i = 0; i < listParticules.size(); i++)
	{
		graviteGenerator.updateforceparticule(&listParticules[i], rate);
		listParticules[i].Integrer(rate);
		listParticules[i].clearAccum();
	}*/
}