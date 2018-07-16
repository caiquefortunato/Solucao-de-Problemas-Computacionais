#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int larg, comp, r1, r2;
	std::ios_base::sync_with_stdio(false);
	
	while(true)
	{
		cin >> larg >> comp >> r1 >> r2;
		if(larg == 0 and comp == 0 and r1 == 0 and r2 == 0)
			break;
		
		//Acho o diametro da circ. dos cilindros
		int d1 = r1 * 2; int d2 = r2 * 2;
		// Guardo outros valores nas variaveis
		int aux1 = larg - (r1 + r2);
		int aux2 = comp - (r1 + r2);
	
		if(d1 > comp or d1 > larg or d2 > comp or d2 > larg)
			cout << "N" << endl;
		
		else
		{
			int pot_soma;
			pot_soma = pow(aux1, 2) + pow(aux2, 2);
			if(pot_soma < pow(r2 + r1, 2))
				cout << "N" << endl;
			else
				cout << "S" << endl;
		}
		
	}

	return 0;
}
