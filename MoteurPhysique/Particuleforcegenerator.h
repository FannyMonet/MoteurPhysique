#pragma once
#include "stdafx.h"
#include "particule.h"
class Particuleforcegenerator
{
public:
	//particule test = particule();
	Particuleforcegenerator();
	
	virtual void updateforceparticule(particule *particule, float duration);

};

