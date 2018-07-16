#include <iostream>
#include <vector>
#include <queue>
#define MAX 2001

using namespace std;

void zera_vetor(bool visitados[])
{
	for(int i = 0; i < MAX; i++)
		visitados[i] = false;
}

int busca_largura(vector<int>grafo[], int vertice,int primeiro)
{
	queue<int>fila;
	bool visitados[MAX];
	zera_vetor(visitados);

	int v, atual, result;
	v = primeiro;
	visitados[v] = true;
	result = 1;
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
				fila.push(atual);
				visitados[atual] = true;
				result += 1;
			}
		} // end of for
	} // end of queue 
	
	return result;
} // end of fuction

int main()
{
	int vertice, aresta, ida, volta, primeiro;
	int resultado, cond;

	while(1)
	{
		cin >> vertice >> aresta;
		if(vertice == 0 and aresta == 0) 
			break;

		vector<int>grafo[MAX];

		for(int i = 0; i < aresta; i++)
		{
			cin >> ida >> volta >> cond;
			if(cond == 1)
				grafo[ida].push_back(volta);
				
			else if(cond == 2)
			{
				grafo[ida].push_back(volta);
				grafo[volta].push_back(ida);
			}	
		}
		
		for(int i = 1; i < vertice + 1; i++)
		{
			primeiro = i;
			resultado = busca_largura(grafo, vertice, primeiro);
			if(resultado != vertice) break;
		}

		if(resultado == vertice)
			cout <<"1"<< endl;
		else
			cout <<"0"<< endl;

	} // end of while

	return 0;
}
