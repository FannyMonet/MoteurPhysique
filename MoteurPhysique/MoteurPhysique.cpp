// MoteurPhysique.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include "particule.h"
#include "MoteurPhysique.h"
#include "chrono"
using namespace std;

int main(int argc, char* argv[]) 
{
	vector<particule> particules;
	particules.emplace_back(5, 5, 5, 10, 50, 20, 1, 0.7, 0);
	particules.emplace_back(5, 5, 5, 0, 40, 0, 2, 0.7, 0);
	particules.emplace_back(5, 5, 5, 3, 25, 30, 3, 0.7, 0);
	
	int estnull = 0;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double, std::milli > elapsedTime;
	float rate = (float) 1/30;
	float totalTime = 0;

	while (estnull == false)
	{	
		start = std::chrono::system_clock::now();

		particules = integrer(particules, rate);
		showResult(particules, totalTime);
		for (int i = 0; i < particules.size(); i++)
		{
			if (particules[i].dimension == 3 && particules[i].position3D.y < 0 || particules[i].dimension==2 && particules[i].position2D.y<0)
				particules.erase(particules.begin() + i);
			if (particules.size() == 0)
				estnull = true;
		}

		totalTime += rate;
		end = std::chrono::system_clock::now();

		elapsedTime = end - start;
		double timeToWait = (double)1000 / 30 - (double)elapsedTime.count();

		if(timeToWait >0)
			Sleep(timeToWait);
	}
	system("PAUSE");
}

vector<particule> integrer(const vector<particule> &particules, double rate)
{
	vector<particule> updatedParticules;
	particule tempParticule;
	for(int i = 0; i < particules.size(); i++)
	{
		tempParticule = particule(particules[i]);
		tempParticule.Integrer(rate);
		updatedParticules.emplace_back(tempParticule);
	}
	return updatedParticules;
}
void showResult(const vector<particule> &particules, double totalTime)
{
	for (int i = 0; i < particules.size(); i++)
	{
		if(particules[i].dimension == 3)
			cout << "La position de la particule " << particules[i].numero << " est : x = " << particules[i].position3D.x << " / y = " << particules[i].position3D.y << " / z =" << particules[i].position3D.z << " metre / temps= " << totalTime << " seconde" << endl;
		else 
			cout << "La position de la particule " << particules[i].numero << " est : x = " << particules[i].position2D.x << " / y = " << particules[i].position2D.y << " metre / temps= " << totalTime << " seconde" << endl;
	}
}