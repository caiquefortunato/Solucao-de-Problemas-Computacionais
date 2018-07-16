#include <iostream>
#include <vector>
#include <queue>
#define MAX 120
#define INF 10000

using namespace std;

void zera_vetor(bool visitados[])
{
	for(int i = 0; i < MAX; i++)
		visitados[i] = false;
}

void zera_vetor(int distancia[], int vertice)
{
	for(int i = 1; i < vertice + 1; i++)
		distancia[i] = INF;	
}

void imprime(int distancia[], int pedagio, int vertice, int teste)
{
	
	cout << "Teste " << teste << endl;
	
	for(int i = 1; i < vertice + 1; i++)
	{
		if(distancia[i] <= pedagio and distancia[i] > 0)
			cout << i << " ";
	}
		
	cout << endl << endl;

}

int busca_largura(vector<int>grafo[], int vertice, int primeiro, int pedagio, int teste)
{

	queue<int>fila; // crio a fila
	bool visitados[MAX]; 
	int distancia[vertice + 1]; // vetor com as distancias da saida
	zera_vetor(visitados);
	zera_vetor(distancia, vertice);

	int v, atual, sum, flag;
	
	v = primeiro; // v recebe o primeiro elemento da busca
	distancia[v] = 0; // defino a base como 0
	visitados[v] = true; // marco a saida como visitado na posicao do vetor
	fila.push(v); // adiciono v na fila

	while(!fila.empty())
	{
		v = fila.front(); // pego o elemento da fila e chamo de v
		fila.pop(); // tiro o elemento da fila

		for(int i = 0; i < grafo[v].size() ; i++) // olho os adj
		{
			atual = grafo[v][i]; // atual eh o vertice adj que estou
			
			if(!visitados[atual])
			{
				fila.push(atual);
				visitados[atual] = true;
				// Realizo as contas
				sum = distancia[v] + 1;
				if(sum < distancia[atual])
					distancia[atual] = sum;
			}
		} // end of for
	} // end of queue 
	
	imprime(distancia, pedagio, vertice, teste);
} // end of fuction

int main()
{
	int vertice, aresta, ida, volta, saida, pedagio;
	int teste;
	teste = 1;

	while(1)
	{
		cin >> vertice >> aresta >> saida >> pedagio;
		if(vertice == 0 and aresta == 0 and saida == 0 and pedagio == 0) 
			break;

		vector<int>grafo[MAX];

		for(int i = 0; i < aresta; i++)
		{
			cin >> ida >> volta;
			grafo[ida].push_back(volta);
			grafo[volta].push_back(ida);	
		}

		busca_largura(grafo, vertice, saida, pedagio, teste);
		teste += 1;
	} // end of while

	return 0;
}
