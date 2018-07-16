#include <iostream>
#include <cstdio>
#include <queue>
#define INF 99999
using namespace std;

int grafo[130][130];

int f_max(int vertice, int sai, int chega);
int busca_largura(int vertice, int sai, int chega, int pai[]);

int f_max(int vertice, int sai, int chega)
{
	int pai[vertice];
	int fluxo_max, u, v, pai_v;
	fluxo_max = 0;
	
	while(busca_largura(vertice, sai, chega, pai))
	{
		u = INF;
		for(v = chega; v != sai; v = pai[v])
		{
			pai_v = pai[v];
			u = min(u, grafo[pai_v][v]);
		}
		
		for(v = chega; v != sai; v = pai[v])
		{
			pai_v = pai[v];
			grafo[pai_v][v] -= u;
			grafo[v][pai_v] += u;
		}
		fluxo_max += u;
	}
	
	return fluxo_max;
}

int busca_largura(int vertice, int sai, int chega, int pai[])
{
	bool visitado[vertice];
	for(int i = 0; i < vertice; i++)
		visitado[i] = 0;
		
	queue <int> fila;
	int atual;
	
	fila.push(sai);
	visitado[sai] = true;
	pai[sai] = -1;
	
	while(!fila.empty())
	{
		atual = fila.front();
		fila.pop();
		
		for(int v = 0; v < vertice; v++)
		{
			if(!visitado[v] and grafo[atual][v] > 0)
			{
				fila.push(v);
				pai[v] = atual;
				visitado[v] = true;
			}
		}
	} // fim do while
	return visitado[chega] == true;
}

int main()
{
	int vertice, aresta, sai, chega, ida, volta, peso, caso, resultado;
	caso = 0;

	while(true)
	{
		scanf("%d", &vertice);
		if(vertice == 0) break;
		caso += 1, resultado = 0;//, vertice += 1;
		
		for(int i = 0; i < vertice; i++)
			for(int j = 0; j < vertice; j++)
				grafo[i][j] = 0;
		
		scanf("%d %d %d", &sai, &chega, &aresta);
		
		for(int i = 0; i < aresta; i++)
		{
			scanf("%d %d %d", &ida, &volta, &peso);
			
			grafo[ida-1][volta-1] += peso;
			grafo[volta-1][ida-1] += peso;
		}
		
		resultado = f_max(vertice, sai-1, chega-1);
		
		printf("Network %d\n", caso);
		printf("The bandwidth is %d.\n\n", resultado);
	}

	return 0;
}
