#include <stdio.h>

void constroi_valores(int moedas[], long vetor[])
{
	vetor[0] = 1;
	for(int i = 0; i < 5; i++)
		for(int j = moedas[i]; j <= 30000; j++)
			vetor[j] += vetor[j - moedas[i]];
}

int main()
{
	int moedas[] = {1, 5, 10, 25, 50};
	long vetor[30010] = {0};
	int valor;

	constroi_valores(moedas, vetor);
	
	while(scanf("%d", &valor) != EOF)
	{
		if(vetor[valor] == 1)
			 printf("There is only %ld way to produce %d cents change.\n", vetor[valor], valor);
		else
			printf("There are %ld ways to produce %d cents change.\n", vetor[valor], valor);
	}

	return 0;
}
