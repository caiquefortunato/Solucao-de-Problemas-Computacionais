#include <vector>
#include <iostream>
#include <queue>
#define INF 10000 // Vertices
#define MAX 10001
using namespace std;

void zera_vetor(int *distancia, int vertice)
{
	for(int i = 0; i < vertice; i++)
		distancia[i] = INF;
}

int Dijkstra(vector<pair<int,int> > grafo[], int vertice, int primeiro)
{
	queue<int>fila;
	int distancia[vertice];
	zera_vetor(distancia, vertice);

	int v, atual, conta = 0;
	v = primeiro;
	distancia[v] = 0;
	
	fila.push(v);

	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();

		for(int i = 0; i < grafo[v].size() ; i++)
		{
			atual = grafo[v][i].first;

			conta = grafo[v][i].second + distancia[v];
			if(conta < distancia[atual])
			{
				distancia[atual] = conta;
				fila.push(atual);
			}
		} // end of for
	} // end of queue 
	
	cout << distancia[vertice-1] << endl;
	return distancia[vertice];
} // end of fuction

int main()
{
	int vertice, aresta, ida, volta, peso;
	ida = 0, volta = 0, peso = 0, vertice = 0, aresta = 0;
	cin >> vertice >> aresta;
	vertice += 2;
	vector<pair<int,int> > grafo[MAX];
	
	for(int i = 0; i < aresta; i++)
	{
		cin >> ida >> volta >> peso;
		grafo[ida].push_back(make_pair(volta, peso));
		grafo[volta].push_back(make_pair(ida, peso));
	} // end of for
	
	Dijkstra(grafo, vertice, 0);

	return 0;
}

