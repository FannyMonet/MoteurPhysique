// MoteurPhysique.cpp : définit le point d'entrée pour l'application console.
//
/*
#include "stdafx.h"
#include <vector>

int main()
{
	
}

*/
//Jeff Chastine
//#include <Windows.h>
#include "stdafx.h"
//#include <GL\glew.h>
//#include <GL\freeglut.h>
#include <iostream>
#include <vector>
#include "vecteur.h"
#include "particule.h"
#include "MoteurPhysique.h"
using namespace std;

void changeViewPort(int w, int h)
{
	/*glViewport(0, 0, w, h);*/
}
/*
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

*/

int main(int argc, char* argv[]) 
{
	vecteur v = vecteur(0, 0, 0);
	particule p = particule(0, 0, 0, v);
	/*
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
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
	*/
}