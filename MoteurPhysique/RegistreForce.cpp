#include "stdafx.h"
#include <iostream>
#include <vector>
#include "RegistreForce.h"

using namespace std;

//Ajoute une particule et sa force dans EnregistrementForce la liste des particules : registre
void RegistreForce::AddEntity(particule * particule, Particuleforcegenerator * Fg) {
	EnregistrementForce en;
	en.particule = particule;
	en.Fg = Fg;
	registre.emplace_back(en);
}
// Supprime la particule et sa force associé de la liste des particules : registre 
void RegistreForce::DeleteEntity(particule * particule, Particuleforcegenerator * Fg)
{
	for (int i = 0; i < registre.size(); i++) {
		if (registre[i].particule == particule && registre[i].Fg == Fg) {
			registre.erase(registre.begin() + 1);
		}
	}
}

// Mise à jour des Forces
void RegistreForce::UpdateEntity(double duration) {
	for (int i = 0; i < registre.size(); i++) {
		registre[i].Fg->updateforceparticule(registre[i].particule, duration);
	}
}