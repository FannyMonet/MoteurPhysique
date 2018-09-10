#pragma once
#include <vector>
using namespace std;

class particule
{
public:
	vector <int> position(vector <int> a, int dim);
	vector <int> vitesse(vector <int> a, int dim);
	vector <int> acceleration(vector <int> a, int dim);
	int dumping;
	int gravitation;
};
