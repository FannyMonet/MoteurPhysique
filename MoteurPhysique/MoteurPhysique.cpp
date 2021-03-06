// MoteurPhysique.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include "particule.h"
#include "MoteurPhysique.h"
#include "chrono"
#include "GameWorld.h"
#include "vecteur3D.h"
#include <GL/gl.h>
#include <GL/glu.h>
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

void display()
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double, std::milli > elapsedTime;
	float rate = (float)1 / 30;
	float totalTime = 0;

	gameWorld.update(rate);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(50, 50, 50, 0, 0, 0, 0, 0, 1);
	for (int i = 0; i < gameWorld.listRectangles.size(); i++)
	{
		drawRectangle(gameWorld.listRectangles[i]);

	}

	totalTime += rate;
	end = std::chrono::system_clock::now();

	elapsedTime = end - start;

	double timeToWait = (double)1000 / 30 - (double)elapsedTime.count();
	if (timeToWait > 0)
		Sleep(timeToWait);

	glFlush();
	glutSwapBuffers();

}
void drawRectangle(RectangleBody rectangle)
{

	/*glRotated(0, 1, 0, 0);
	glRotated(0, 0, 1, 0);
	glRotated(0, 0, 0, 1);*/
	glPointSize(5);

	glBegin(GL_POINTS);
	glVertex3f(rectangle.position.x, rectangle.position.y, rectangle.position.z);
	glEnd();

	glBegin(GL_QUADS);


	for (int i = 0; i < 8; i++)
	{
		rectangle.points[i] = rectangle.points[i].localToWorld(rectangle.transformMatrice);
	}

	glPushMatrix();
	glColor3ub(255, 0, 0); //face rouge
	glVertex3d(rectangle.points[0].x, rectangle.points[0].y, rectangle.points[0].z);
	glVertex3d(rectangle.points[1].x, rectangle.points[1].y, rectangle.points[1].z);
	glVertex3d(rectangle.points[5].x, rectangle.points[5].y, rectangle.points[5].z);
	glVertex3d(rectangle.points[4].x, rectangle.points[4].y, rectangle.points[4].z);

	glColor3ub(0, 255, 0); //face verte
	glVertex3d(rectangle.points[2].x, rectangle.points[2].y, rectangle.points[2].z);
	glVertex3d(rectangle.points[3].x, rectangle.points[3].y, rectangle.points[3].z);
	glVertex3d(rectangle.points[1].x, rectangle.points[1].y, rectangle.points[1].z);
	glVertex3d(rectangle.points[0].x, rectangle.points[0].y, rectangle.points[0].z);

	glColor3ub(0, 0, 255); //face bleue
	glVertex3d(rectangle.points[6].x, rectangle.points[6].y, rectangle.points[6].z);
	glVertex3d(rectangle.points[7].x, rectangle.points[7].y, rectangle.points[7].z);
	glVertex3d(rectangle.points[3].x, rectangle.points[3].y, rectangle.points[3].z);
	glVertex3d(rectangle.points[2].x, rectangle.points[2].y, rectangle.points[2].z);

	glColor3ub(255, 255, 0); //face jaune
	glVertex3d(rectangle.points[4].x, rectangle.points[4].y, rectangle.points[4].z);
	glVertex3d(rectangle.points[5].x, rectangle.points[5].y, rectangle.points[5].z);
	glVertex3d(rectangle.points[7].x, rectangle.points[7].y, rectangle.points[7].z);
	glVertex3d(rectangle.points[6].x, rectangle.points[6].y, rectangle.points[6].z);

	glColor3ub(0, 255, 255); //face cyan
	glVertex3d(rectangle.points[1].x, rectangle.points[1].y, rectangle.points[1].z);
	glVertex3d(rectangle.points[3].x, rectangle.points[3].y, rectangle.points[3].z);
	glVertex3d(rectangle.points[7].x, rectangle.points[7].y, rectangle.points[7].z);
	glVertex3d(rectangle.points[5].x, rectangle.points[5].y, rectangle.points[5].z);
	
	glColor3ub(255, 0, 255); //face magenta
	glVertex3d(rectangle.points[2].x, rectangle.points[2].y, rectangle.points[2].z);
	glVertex3d(rectangle.points[0].x, rectangle.points[0].y, rectangle.points[0].z);
	glVertex3d(rectangle.points[4].x, rectangle.points[4].y, rectangle.points[4].z);
	glVertex3d(rectangle.points[6].x, rectangle.points[6].y, rectangle.points[6].z);
	glPopMatrix();
	glEnd();
	for (int i = 0; i < 8; i++)
	{
		rectangle.points[i] = rectangle.points[i].worldToLocal(rectangle.transformMatrice.inverse());
	}
/*
	//glBegin(GL_QUADS);
	glPushMatrix();
	glColor3d(1, 0, 0);
	glVertex3f(-1, -1, -10);
	glColor3d(1, 1, 0);
	glVertex3f(1, -1, -10);
	glColor3d(1, 1, 1);
	glVertex3f(1, 1, -10);
	glColor3d(0, 1, 1);
	glVertex3f(-1, 1, -10);
	glPopMatrix();
	glEnd();*/


	glBegin(GL_POINTS);
	glColor3f(0.3, 0.3, 0.3);
	glPointSize(5.0f);  // wat
	glVertex2i(0, 0);
	glEnd();

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