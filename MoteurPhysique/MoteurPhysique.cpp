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

#define PI 3.1415926535897932384626433832795
#define WIDTH 800
#define HEIGHT 600

using namespace std;

void reshape(int, int);
void display();
void showResult(const vector<particule> &particules, double totalTime);

//Specifies the radius of the circle
static int radius = 2;
static GameWorld gameWorld = GameWorld();
using namespace std;

int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Hello, GL");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}
void display()
{
	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	//Set Drawing Color - Will Remain this color until otherwise specified
	glColor3f(0.2, 0.3, 0.5);  //Some type of blue

	int estnull = 0;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double, std::milli > elapsedTime;
	float rate = (float)1 / 30;
	float totalTime = 0;

	start = std::chrono::system_clock::now();

	gameWorld.update(rate);

	//showResult(gameWorld.listParticules, totalTime);
	for (int i = 0; i < gameWorld.listParticules.size(); i++)
	{
		drawFilledCircle(gameWorld.listParticules[i].position3D.x, gameWorld.listParticules[i].position3D.y, 2);

		if (gameWorld.listParticules[i].dimension == 3 && gameWorld.listParticules[i].position3D.y < 0 || gameWorld.listParticules[i].dimension == 2 && gameWorld.listParticules[i].position2D.y < 0)
			gameWorld.listParticules.erase(gameWorld.listParticules.begin() + i);

		if (gameWorld.listParticules.size() == 0)
			estnull = true;
	}

	totalTime += rate;
	end = std::chrono::system_clock::now();

	elapsedTime = end - start;
	double timeToWait = (double)1000 / 30 - (double)elapsedTime.count();

	if (timeToWait > 0)
		Sleep(timeToWait);
	glPopMatrix();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}
void showResult(const vector<particule> &particules, double totalTime)
{
	for (int i = 0; i < particules.size(); i++)
	{
		if (particules[i].dimension == 3)
			cout << "La position de la particule " << particules[i].numero << " est : x = " << particules[i].position3D.x << " / y = " << particules[i].position3D.y << " / z =" << particules[i].position3D.z << " metre / temps= " << totalTime << " seconde" << endl;
		else
			cout << "La position de la particule " << particules[i].numero << " est : x = " << particules[i].position2D.x << " / y = " << particules[i].position2D.y << " metre / temps= " << totalTime << " seconde" << endl;
	}
}