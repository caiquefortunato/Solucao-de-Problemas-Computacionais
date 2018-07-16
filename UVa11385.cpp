#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <map>
#define MAX 44
#define MAX2 1001
using namespace std;

// Cria o map
map <int, int> map_fibonacci;

// Pre calcula os valores dos fatoriais usando PD
// Mapeia os dados calculados do fibonacci
void calcula_fibonacci(int fibonacci[])
{
	fibonacci[0] = 1; fibonacci[1] = 2;
	map_fibonacci[1] = 0; map_fibonacci[2] = 1;
	
	for(int i = 2; i < MAX; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		map_fibonacci[fibonacci[i]] = i;
	}
} // end of Fibonacci function

int main()
{
	int entrada, itens;
	cin >> entrada;
	//ios::sync_with_stdio(false);
	int fibonacci[MAX];
	memset(fibonacci, 0, sizeof(fibonacci));
	calcula_fibonacci(fibonacci);	

	for(int i = 0; i < entrada; i++)
	{
		cin >> itens;
		int numeros[itens + 1], numero;
		char aux[MAX2];
		string letras;
		memset(aux, ' ', sizeof(aux));
		int max = 0;
		
		// Leio a chave de criptografia 
		// Salvo o valor maximo da chave
		for(int l = 0; l < itens; l++)
		{
			cin >> numero; numeros[l] = numero;
			if(numero > max) max = numero;
		}
		
		getchar();
		getline(cin, letras);
		/*
		int aff = 0; char affa;
		while(1)
		{
			scanf("%c", &affa);
			if(affa == '\n') break;
			letras[aff] = affa;
		
		}
		
		// Leio as letras da chave considerando letras
		
		/*
		int cont = 0; char c;
		while(1)
		{
			cin >> c;
			if(c == '\n') break;
			// Considera apenas as letras 65 ate 90 na ASCII
			if(isupper(c)){letras[cont] = c; cont++;}
		} // end of read
		*/
		
		aux[map_fibonacci[max] + 1] = 0;
		
		int cont = 0;
		for(int a = 0; a < itens; a++)
		{
			while(!isupper(letras[cont])) cont++;
			aux[map_fibonacci[numeros[a]]] = letras[cont];
			cont++;
		}
		
		/*
		for(int a = 0; a < cont; a++)
			cout << aux[a];
		cout << endl;
		*/
		
		printf("%s", aux);
		cout << endl;
	} // end of for 

	return 0;
}
