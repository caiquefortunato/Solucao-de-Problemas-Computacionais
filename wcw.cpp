#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	int entrada, quantidade, resp, aux;

	cin >> entrada;

	// casos de teste dado na entrada
	for(int i = 0; i < entrada; i++)
	{
		resp = 0;
		cin >> quantidade;
		int vetor[quantidade + 1];
		memset(vetor, 0, sizeof(vetor));

		for(int j = 1; j < quantidade + 1; j++)
			cin >> vetor[j];	

		for(int k = 1; k < quantidade; k++)
		{
			if(vetor[k] != k)
			{
				// troco as variaveis
				aux = vetor[k];
				vetor[k] = vetor[aux];
				vetor[aux] = aux;
				// atualizo a posicao
				// incremento o numero de troca
				k -= 1; resp += 1;
			}
		}

		cout << resp << endl;
	}
	
	return 0;
}
