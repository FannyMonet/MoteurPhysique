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
#include <chrono>
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
	particule p = particule(0, 0, 0, 2,3,4);

	auto start = std::chrono::system_clock::now();
	while 
	std::chrono::duration<double> elapsed_seconds = end - start;
	auto end = std::chrono::system_clock::now();
	cout << "la position de la particule est : x =" << p.x << "y = " << p.y << "z =" << p.z << " metre" << endl;


	
	

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