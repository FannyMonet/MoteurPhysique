// MoteurPhysique.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include "particule.h"
#include "MoteurPhysique.h"
#include "chrono"
#include "GameWorld.h"
#include "../freeglut/include/GL/freeglut.h"
#include "../freeglut/include/GL/glut.h"
#include <iostream>

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

using namespace std;

int main(int argc, char* argv[]) 
{
	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, GL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.



	glutMainLoop();
	return 0;
	GameWorld gameWorld = GameWorld();
	int estnull = 0;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double, std::milli > elapsedTime;
	float rate = (float) 1/30;
	float totalTime = 0;

	while (estnull == false)
	{	
		start = std::chrono::system_clock::now();

		gameWorld.update(rate);

		showResult(gameWorld.listParticules, totalTime);
		for (int i = 0; i < gameWorld.listParticules.size(); i++)
		{
			if (gameWorld.listParticules[i].dimension == 3 && gameWorld.listParticules[i].position3D.y < 0 || gameWorld.listParticules[i].dimension==2 && gameWorld.listParticules[i].position2D.y<0)
				gameWorld.listParticules.erase(gameWorld.listParticules.begin() + i);

			if (gameWorld.listParticules.size() == 0)
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