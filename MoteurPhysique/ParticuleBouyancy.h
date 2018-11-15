#pragma once
#include "Particuleforcegenerator.h"

class ParticuleBouyancy :
	public Particuleforcegenerator
{
public:
	ParticuleBouyancy(float Vprofmax, float Vvolumeobjet, float Vhauteureau, float Vdensite)
	{
		profmax = Vprofmax;
		volumeobjet = Vvolumeobjet;
		hauteureau = Vhauteureau;
		densite = Vdensite;
	};

	float profmax;
	float volumeobjet;
	float hauteureau;
	float densite;

	virtual void updateforceparticule(particule particule, float duration);
};

