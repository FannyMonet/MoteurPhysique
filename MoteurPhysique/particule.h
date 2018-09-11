#pragma once
#include <vector>
using namespace std;

class particule
{
public:
	vector <int> Position(vector <int> a, int dim);
	vector <int> Vitesse(vector <int> a, int dim);
	vector <int> Acceleration(vector <int> a, int dim);
	int Dumping;
	int Gravitation; 
	int Inverse_Masse(int Masse);
	void Integrer(float temps);

};
