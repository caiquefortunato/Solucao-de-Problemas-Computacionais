#include <cstdio>
#include <string.h>
#include <iostream>
#define INF 99999
using namespace std;

int coin_change(int moedas[], int moeda, int valor)
{
	int dinamico[valor + 1];
	dinamico[0] = 0;
	
	for(int i = 1; i <= valor; i++)
	{
		dinamico[i] = INF;
		
		for(int j = 0; j < moeda; j++)
		{
			if(i - moedas[j] >= 0)
				dinamico[i] = min(dinamico[i], dinamico[i - moedas[j]] + 1);
		}
		
	}
	return dinamico[valor];
}

int main()
{
	int valor, moeda, moedas[101], result;

	while(true)
	{
		scanf("%d %d", &valor, &moeda);
		if(valor == 0) break;
		
		memset(moedas, 0, sizeof(moedas));
		// Realizacao da leitura de valores
		for(int i = 0; i < moeda; i++)
			scanf("%d", &moedas[i]);
		
		result = coin_change(moedas, moeda, valor);
		
		if(result == INF)
			printf("Impossivel\n");
		else
			printf("%d\n", result);
			
	}
		
	return 0;		
}
