#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define MAX 120
int cores[MAX]; // inicializo vetor de cores

using namespace std;

void zera_vetor(bool visitados[])
{
	for(int i = 0; i < MAX; i++)
		visitados[i] = false;
}

int zera_cor(int *cores, int vertice)
{
	for(int i = 0; i < vertice + 1; i++)
		cores[i] = 0;
}

int busca_largura(vector<int>grafo[], int vertice, int primeiro, int *cores)
{
	queue<int>fila;
	bool visitados[MAX];
	//int cores[vertice + 1]; // inicializo vetor de cores
	zera_vetor(visitados);

	int v, atual, result;
	result = 0;
	v = primeiro;
	visitados[v] = true;
	cores[v] = 1;
	fila.push(v);

	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();

		for(int i = 0; i < grafo[v].size() ; i++)
		{
			atual = grafo[v][i];

			if(!visitados[atual])
			{
				// se existe v adj e nao foi colorido
				if(cores[atual] == 0)
				{
					if(cores[v] == 1)
						cores[atual] = 2;
					else
						cores[atual] = 1;
				}
				// se existe e tem a mesma cor
				if(cores[atual] == cores[v])
				{
					result = 1;
					return 1;
					break;
				}
				fila.push(atual);
				
			}
		} // end of for
		visitados[atual] = true;
	} // end of queue 
	
	return result;
} // end of fuction

int main()
{
	int vertice, aresta, ida, volta, primeiro;
	int resultado, n_teste;
	n_teste = 1;

	while(scanf("%d %d", &vertice, &aresta) != EOF)
	{
		vector<int>grafo[MAX];
		// zero meu vetor de cores 	
		zera_cor(cores, vertice);

		for(int i = 0; i < aresta; i++)
		{
			scanf("%d %d", &ida, &volta);
			if(i == 0)
				primeiro = ida;
			grafo[ida].push_back(volta);
			grafo[volta].push_back(ida);	
		}

		for(int i = 1; i < vertice + 1; i++)
		{
			if(cores[i] == 0)
			{
				resultado = busca_largura(grafo, vertice, primeiro, cores);
				if(resultado == 1) break;
			}
		}
		
		printf("Instancia %d\n", n_teste);
		n_teste++;
		if(resultado == 1)
			printf("nao\n");
		else if(resultado == 0)
			printf("sim\n");

		printf("\n");
	} // end of while

	return 0;
}
