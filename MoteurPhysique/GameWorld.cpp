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
	listRectangles.emplace_back( RectangleBody(vecteur3D(-20,0,0), vecteur3D(0, 0, 0), vecteur3D(0, 0, 0), 0.9, 0.7, vecteur3D(1, 2, 1) ));
	collisionData = CollisionData();
}

void GameWorld::update(float rate)
{
	integrer(rate);
}

void GameWorld::integrer(float rate)
{
	octree = new Octree(vecteur3D(0, 0, 0), vecteur3D(25, 25, 25));	
	octreePoints = new OctreePoint[7];
	//OctreePoint *newPoint;
	for (int i = 0; i < listRectangles.size(); i++)
	{
		listRectangles[i].Integrer(rate);
		for (int j = 0; j < 8; j++)
		{
			/*newPoint = new OctreePoint();
			newPoint->setPosition(listRectangles[i].points[j]);
			octree->insert(newPoint);*/
			octreePoints[i].setPosition(listRectangles[i].points[j]);
			

		}octree->insert(octreePoints);
	}
	vector<OctreePoint*> results;
	
	octree->getPointsInsideBox(vecteur3D(-12.25, -12.25, -12.25), vecteur3D(12.25, 12.25, 12.25), results);
	

}

void GameWorld::generateContacts(Primitive prim1, Primitive prim2, CollisionData * data) 
{

}