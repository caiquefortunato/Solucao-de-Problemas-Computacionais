#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
#define INF 10000 // Vertices
#define MAX 10001
using namespace std;

void verifica_caminho(vector<pair<int,int> > grafo[], int caminho, int *distancia)
{
	int chegada, pos; 
	chegada = caminho - 1;
	distancia[chegada] = 0;
	
	for(int i = caminho - 2; i >= 0; i--)
	{
		for(int j = 0; j < grafo[i].size(); j++)
			if(i + 1 == grafo[i][j].first) pos = j;
		
		distancia[i] = distancia[i + 1] + grafo[i][pos].second;
	}
	
}
		
void zera_vetor(int *distancia, int vertice)
{
	for(int i = 0; i < vertice; i++)
		distancia[i] = INF;
}

void Dijkstra(vector<pair<int,int> > grafo[], int vertice, int primeiro, int *d_caminho, int caminho)
{
	queue<int>fila;
	int distancia[vertice];
	zera_vetor(distancia, vertice);

	int v, atual, conta = 0, total = INF, t_temp = 0;
	v = primeiro;
	distancia[v] = 0;
	
	int flag = 0;
	
	fila.push(v);

	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();

		for(int i = 0; i < grafo[v].size() ; i++)
		{
			atual = grafo[v][i].first;
			
			conta = grafo[v][i].second + distancia[v];
			
			if(atual <= caminho - 1)
			{
				//cout << "atual " << atual << endl;
				t_temp = conta + d_caminho[atual];
				if(total > t_temp) total = t_temp;
			}

			else if(conta < distancia[atual])
			{
				distancia[atual] = conta;
				fila.push(atual);
			}
		} // end of for
	} // end of queue 
	
	cout << total << endl;
} // end of fuction

int main()
{
	int vertice, aresta, caminho, lost;
	int ida, volta, peso;
	
	while(1)
	{
		vertice = 0, aresta = 0, caminho = 0;
		lost = 0, ida = 0, volta = 0, peso = 0;
		
		scanf("%d %d %d %d", &vertice, &aresta, &caminho, &lost);
		if(vertice == 0 and aresta == 0 and caminho == 0) break;
		
		// Crio o vetor p/ repesentar grafo
		vector<pair<int, int> > grafo[MAX];
		int distancia[caminho] = {0};
		
		for(int i = 0; i < aresta; i++)
		{
			scanf("%d %d %d", &ida, &volta, &peso);
			grafo[ida].push_back(make_pair(volta, peso));
			grafo[volta].push_back(make_pair(ida, peso));
		}
		
		verifica_caminho(grafo, caminho, distancia);
		Dijkstra(grafo, vertice, lost, distancia, caminho);
		
	}

	return 0;
}

