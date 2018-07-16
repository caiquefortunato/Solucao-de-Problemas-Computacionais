#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int entrada, voto, maior, ganhador;
	maior = 0;
	cin >> entrada;

	map<int, int>eleicao;

	for(int i = 0; i < entrada; i++)
	{
		cin >> voto;
		//Olhar se existe no map
		if(eleicao.count(voto))
		{
			eleicao[voto] += 1;
			if(eleicao[voto] > maior)
			{
				ganhador = voto;
				maior = eleicao[voto];
			}
		}
		else
		{
			eleicao[voto] = 1;
			if(eleicao[voto] > maior)
			{
				ganhador = voto;
				maior = 1;
			}
		}
	}

	cout<<ganhador<<endl;

	return 0;
}
