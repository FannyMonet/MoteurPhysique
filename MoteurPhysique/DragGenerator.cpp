#include "stdafx.h"
#include "DragGenerator.h"

using namespace std;

DragGenerator::DragGenerator()
{
}

DragGenerator::DragGenerator(float Vk1, float Vk2)
{
	K1 = Vk1;
	K2 = Vk2;
}

void DragGenerator::updateforceparticule(particule* particule, float duration)
{	
	int dim = particule->dimension;
	if (dim == 2)
	{
		drag2D = vecteur2D((-K1*particule->vitesse2D.x-K2*particule->vitesse2D.x*particule->vitesse2D.x), (-K1*particule->vitesse2D.y - K2*particule->vitesse2D.y*particule->vitesse2D.y));
		particule->addForce(drag2D);
	}
	if (dim == 3)
	{
		drag3D = vecteur3D((-K1*particule->vitesse3D.x - K2*particule->vitesse3D.x*particule->vitesse3D.x), (-K1*particule->vitesse3D.y - K2*particule->vitesse3D.y*particule->vitesse3D.y), (-K1*particule->vitesse3D.z - K2*particule->vitesse3D.z*particule->vitesse3D.z));
		particule->addForce(drag2D);
	}
}

void DragGenerator::updateForceRigidBody(vecteur3D velocity, vecteur3D rotation, vecteur3D* forceAccum, vecteur3D* torqueAccum, float duration)
{
	forceAccum->x += -K1 * velocity.x - K2 * velocity.x*velocity.x;
	forceAccum->y += -K1 * velocity.y - K2 * velocity.y*velocity.y;
	forceAccum->z += -K1 * velocity.z - K2 * velocity.z*velocity.z;

	torqueAccum->x += -K1 * rotation.x - K2 * rotation.x*rotation.x;
	torqueAccum->y += -K1 * rotation.y - K2 * rotation.y*rotation.y;
	torqueAccum->z += -K1 * rotation.z - K2 * rotation.z*rotation.z;
}

