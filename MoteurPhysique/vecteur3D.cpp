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
vecteur3D::vecteur3D(const vecteur3D &vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
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
	return vecteur3D(x * k, y * k, z * k);
}

vecteur3D vecteur3D::addForce(vecteur3D &force)
{
	return vecteur3D(x + force.x, y * force.y, z * force.z);
}
vecteur3D vecteur3D::clearAccum()
{
	return vecteur3D(0, -9.81, 0);
}

vecteur3D vecteur3D::localToWorld(Matrice3 transfMatrice)
{
	return vecteur3D(	transfMatrice.coef[0] * x + transfMatrice.coef[1] * y + transfMatrice.coef[2] * z, 
						transfMatrice.coef[3] * x + transfMatrice.coef[4] * y + transfMatrice.coef[5] * z, 
						transfMatrice.coef[6] * x + transfMatrice.coef[7] * y + transfMatrice.coef[8] * z
	);
}
vecteur3D vecteur3D::worldToLocal(Matrice3 inverseTransfMatrice)
{
	return vecteur3D(	inverseTransfMatrice.coef[0] * x + inverseTransfMatrice.coef[1] * y + inverseTransfMatrice.coef[2] * z,
						inverseTransfMatrice.coef[3] * x + inverseTransfMatrice.coef[4] * y + inverseTransfMatrice.coef[5] * z,
						inverseTransfMatrice.coef[6] * x + inverseTransfMatrice.coef[7] * y + inverseTransfMatrice.coef[8] * z
	);
}
