/*
Autor: Caíque Bruno Fortunato
Solução do problema: B. Choosing Symbol Pairs
Choosing Symbol Pairs (http://codeforces.com/problemset/problem/50/B)
Código: Aceito
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int numeros[123];
    memset(numeros, 0, sizeof(numeros));
    
    string texto;
    
    getline(cin, texto);
    long long len = texto.size();
    long long result = 0;
     
    for(int i = 0; i < len; i++)
    	numeros[texto[i]] += 1;

    for(int i = 47; i <= 122; i++)
    	result += pow(numeros[i], 2);
    
    cout << result << '\n';

    return 0;
    
}
