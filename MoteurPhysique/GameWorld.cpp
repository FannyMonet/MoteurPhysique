#include "stdafx.h"
#include "GameWorld.h"
#include <vector>

using namespace std;

GameWorld::GameWorld()
{
	listRectangles = vector<RectangleBody>();
	registre = RegistreForce();
	resolver = ParticuleContactResolver();
	graviteGenerator = GeneratorForceGravite();
	dragGenerator = DragGenerator(0.2, 0.3);
	listRectangles.emplace_back( RectangleBody(vecteur3D(0,0,0), vecteur3D(0, 15, 0), vecteur3D(0, 0, 0), vecteur3D(0, 0, 0), 0.1, 0.1, vecteur3D(2, 4, 2) ));
}

void GameWorld::update(float rate)
{
	integrer(rate);
}

void GameWorld::integrer(float rate)
{
	for (int i = 0; i < listRectangles.size(); i++)
	{
		listRectangles[i].Integrer(rate);
	}
}