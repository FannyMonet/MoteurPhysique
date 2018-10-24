#include "stdafx.h"
#include "vecteur3D.h"
#include <iostream>

using namespace std;

vecteur3D::vecteur3D()
{
	x = 0;
	y = 0;
	z = 0;
}
vecteur3D::vecteur3D(float dx, float dy, float dz)
{
	x = dx;
	y = dy;
	z = dz;
}

vecteur3D vecteur3D::Addition(vecteur3D &vec)
{
	return vecteur3D(vec.x + x, vec.y + y, vec.z + z);
}

float vecteur3D::Produit_Scalaire(vecteur3D &vec)
{
	return vec.x * x + vec.y * y + vec.z * z;
}

vecteur3D vecteur3D::Produit_de_Composante(vecteur3D &vec)
{
	return vecteur3D(vec.x * x, vec.y * y, vec.z * z);
}

double vecteur3D::Norme()
{
	return sqrt(x*x + y * y + z * z);
}

vecteur3D vecteur3D::Multiplication_Scalaire(float k)
{
	return vecteur3D(x * k, y * k, z * k);;
}

vecteur3D vecteur3D::addForce(vecteur3D &force)
{
	return vecteur3D(x + force.x, y * force.y, z * force.z);;
}
vecteur3D vecteur3D::clearAccum()
{
	return vecteur3D(0, -9.81, 0);;;
}