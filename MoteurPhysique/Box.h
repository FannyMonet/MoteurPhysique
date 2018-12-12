#pragma once
#include "vecteur3D.h"
#include "Primitive.h"

class Box : public Primitive
{
public:
	vecteur3D halfsizes;
	Box();
	Box(RectangleBody* body);
};

