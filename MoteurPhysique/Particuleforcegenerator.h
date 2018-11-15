#pragma once
#include "stdafx.h"
#include "particule.h"

class Particuleforcegenerator
{
public:
	Particuleforcegenerator();
	
	virtual void updateforceparticule(particule *particule, float duration);

};

