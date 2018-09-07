
#include <vector>
using namespace std;

class vecteur
{
public:
	vector<int> Addition(vector<int> a, vector<int> b, int dim);
	int Produit_Scalaire(vector<int> a, vector<int> b, int dim);
	vector<int> Produit_de_Composante(vector<int> a, vector<int> b, int dim);
	int Norme(vector<int> a, int dim);
	vector<int> Multiplication_Scalaire(vector<int> a, int k, int dim);
	Calcul_Integral();
};

