#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Arvore
{
	int p1, p2, tempo, n_max;
} Arvore;

int distancia(Arvore a, Arvore b)
{
	int distancia;
	distancia = max(abs(a.p1 - b.p1), abs(a.p2 - b.p2));
	return distancia;
}

int main()
{
	ios::sync_with_stdio(false);

	int linha, dist, coluna, n_maca, p1, p2, tempo, n_max;

	while(1)
	{
		cin >> linha >> coluna >> n_maca;
		if(linha == 0 and coluna == 0 and n_maca == 0) break;
		Arvore a[n_maca + 1];
		
		for(int i = 1; i <= n_maca; i++)
			cin >> a[i].p1 >> a[i].p2 >> a[i].tempo;

		cin >> a[0].p1 >> a[0].p2;
		a[0].tempo = 0;

		for(int i = n_maca; i >= 0; i--)
		{
			int maior = 1;
			for(int j = i + 1; j <= n_maca; j++)
			{
				dist = distancia(a[i], a[j]);

				if(dist <= a[j].tempo - a[i].tempo)
				{
					if(maior < a[j].n_max + 1)
						maior = 1 + a[j].n_max;
				}
			}
			a[i].n_max = maior;
		} // end of for

		cout << a[0].n_max - 1 << endl;
	} // end of while



	return 0;
}

