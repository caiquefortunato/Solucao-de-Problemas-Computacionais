#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool compara(char a, char b)
{
	return (a < b);
}

int main()
{
	int entrada, total, len;
	string mdna;

	while(1)
	{
		total = 0, len = 0;

		cin >> entrada;
		if(entrada == 0) break;
	
		map<string, int>aliens;
	
		for(int i = 0; i < entrada; i++)
		{
			cin >> mdna;
			len = mdna.size();
	
			sort(mdna.begin(), mdna.end(), compara);
			// Ordenar as palavras
			if(!aliens.count(mdna))		
			{
				aliens[mdna] = 1;
				total += 1;	
			}
	
		} // Fim do for de condicao

		cout<<total<<endl;	

	}
	return 0;
}
