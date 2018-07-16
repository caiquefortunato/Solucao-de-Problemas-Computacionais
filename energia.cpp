#include <iostream>
#include <vector>
#include <queue>
#define MAX 120

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
	int resultado, n_teste;
	n_teste = 1;

	while(1)
	{
		cin >> vertice >> aresta;
		if(vertice == 0 and aresta == 0) 
			break;

		vector<int>grafo[MAX];

		for(int i = 0; i < aresta; i++)
		{
			cin >> ida >> volta;
			if(i == 0)
				primeiro = ida;
			grafo[ida].push_back(volta);
			grafo[volta].push_back(ida);	
		}

		resultado = busca_largura(grafo, vertice, primeiro);

	    cout << "Teste " << n_teste << endl;
		n_teste++;
		if(resultado == vertice)
			cout <<"normal" << endl;
		else
			cout <<"falha"<< endl;

		cout << endl;
	} // end of while

	return 0;
}
