/*
Caíque Bruno Fortunato
Spoj: caiquebf
Problema: ONZE - Você pode dizer 11	
Link: http://br.spoj.com/problems/ONZE/
*/
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	char numero[1001], unidade[2];
	int tamanho, s_par, s_impar, total, atual, result;

	while(1)
	{
		cin.getline(numero, 1001);
		tamanho = strlen(numero);
		result = atoi(numero);
		if(result == 0) break;
		
		s_par = 0; s_impar = 0, total = 0; unidade[1] = '\0';
		
		for(int i = 0; i < tamanho; i++)
		{	
			unidade[0] = numero[i];
			atual = atoi(unidade);
			if(i % 2 == 0)
				s_par += atual;
			else
				s_impar += atual;
		}

		total = s_par - s_impar;

		if(total % 11 == 0) 
			cout << numero <<" is a multiple of 11." << endl;
		else
			cout << numero <<" is not a multiple of 11." << endl;
	}

	return 0;
}
