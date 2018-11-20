#include "stdafx.h"
#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion()
{
	w, x, y, z = 0;
}

Quaternion::Quaternion(double _w, double _x, double _y, double _z)
{
	w = _w;
	x = _x;
	y = _y;
	z = _z;
}

Quaternion::Quaternion(Quaternion* q)
{
	w = q->w;
	x = q->x;
	y = q->y;
	z = q->z;

}
Quaternion Quaternion::operator*=(Quaternion q)
{
	return Quaternion(	w * q.w - x * q.x - y * q.y - z * q.z,
						w * q.x + q.w * x + y * q.z - z * q.y,
						w * q.y + q.w * y + z * q.x - x * q.z,
						w * q.z + z * q.w + x * q.y - y * q.x);
}

void Quaternion::normalize()
{
	double det = w * w + x * x + y * y + z * z;
	if (det == 0)
	{
		w = 1;
		x, y, z = 0;
	}
	else
	{
		det = (double) 1 / sqrt(det);
		w *= det;
		x *= det;
		y *= det;
		z *= det;
	}
}
void Quaternion::effectuerRotation(vecteur3D v)
{
	Quaternion q = Quaternion(0, v.x, v.y, v.z);
	q *= Quaternion(w, x, y, z);
	w = q.w;
	x = q.x;
	y = q.y;
	z = q.z;
}
void Quaternion::updateVelociteAngulaire(vecteur3D velocite, float temps)
{
	 
}

Matrice3 Quaternion::convertToMatrice()
{
	return Matrice3( 1 - (2*y*y + 2*z*z),
					 2*x*y - 2*z*w,
					 2*x*z - 2*y*w,
					 2*x*y - 2*z*w,
					 1 - (2*x*x + 2*z*z),
					 2*y*z + 2*x*w,
					 2*x*z + 2*y*w,
					 2*y*z - 2*x*w,
					 (1 - (2*x*x + 2*y*y))
	);
}
void Quaternion::updateVelociteAngulaire(vecteur3D velocite, float temps)
{
	Quaternion oldVelocity = Quaternion(this);
	(*this) *= Quaternion(0, velocite.x, velocite.y, velocite.z);
	w = oldVelocity.w + temps / 2 * w;
	x = oldVelocity.x + temps / 2 * x;
	y = oldVelocity.y + temps / 2 * y;
	z = oldVelocity.z + temps / 2 * z;
}