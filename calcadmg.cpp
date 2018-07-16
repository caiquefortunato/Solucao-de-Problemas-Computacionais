/*
Caíque Bruno Fortunato
Spoj: caiquebf
Problema: CALCADMG - Caminhando pela calçada
Link: http://br.spoj.com/problems/CALCADMG/
*/

#include <iostream>
#include <cmath>

using namespace std;

int calcula_mdc(int x, int y)
{
	if(y == 0) return x;
	else return calcula_mdc(y, x % y);
}

int main()
{
	ios::sync_with_stdio(false);

	int teste, a, b, c, d;
	int calc1, calc2, resp;

	cin >> teste;

	for(int i = 0; i < teste; i++)
	{
		cin >> a >> b >> c >> d;
		calc1 = abs(c - a);
		calc2 = abs(d - b);
		resp = calcula_mdc(calc1, calc2) + 1;
		cout << resp << endl;
	}

	return 0;
}
