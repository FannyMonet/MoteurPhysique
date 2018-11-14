#pragma once
class Matrice3
{
public:
	float matrice3[3][3] = { {1,2,3}, {1,2,3} ,{1,2,3} };
	Matrice3();
	float ** MultiplicationMatriceUnitaire(float  matrice3[3][3]);
	float ** MultiplicationMatrice(float matrice3[3][3], float  matrice3bis[3][3]);
	float ** InverseMatrice3(float matrice3[3][3]);
	float ** TransposeMatrice3();
	~Matrice3();
};

