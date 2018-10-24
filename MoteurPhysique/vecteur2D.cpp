#include "stdafx.h"
#include "vecteur2D.h"
#include <iostream>


// Constructeurs

vecteur2D::vecteur2D()
{
	x = 0;
	y = 0;
}

vecteur2D::vecteur2D(float dx, float dy)
{
	x = dx;
	y = dy;
}

//Méthodes

vecteur2D vecteur2D::Addition(vecteur2D &vec)
{
	return vecteur2D(vec.x + x, vec.y + y);;
}

float vecteur2D::Produit_Scalaire(vecteur2D &vec)
{
	return vec.x * x + vec.y * y;
}

vecteur2D vecteur2D::Produit_de_Composante(vecteur2D &vec)
{
	return vecteur2D(vec.x * x, vec.y * y);
}

double vecteur2D::Norme()
{
	return sqrt(x*x + y * y);
}

vecteur2D vecteur2D::Multiplication_Scalaire(float k)
{
	return vecteur2D(x * k, y * k);
}

vecteur2D vecteur2D::addForce(vecteur2D &force)
{
	return vecteur2D(x + force.x, y * force.y);
}

vecteur2D vecteur2D::clearAccum()
{
	return vecteur2D(0, -9.81);
}