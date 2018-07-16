#include <iostream>
#define NEGATIVO -1
using namespace std;

int main()
{
	int musicos, tocam_juntos, par1, par2, nivel;
	int total, total_temp;
	int banda[3];

	total = NEGATIVO;

	cin >> musicos >> tocam_juntos;
	int matriz[musicos + 1][musicos + 1];

	// zero a matriz
	for(int i = 0; i < musicos + 1; i++)
		for(int j = 0; j < musicos + 1; j++)
			matriz[i][j] = 0;

	// Monto o grafo conforme a entrada
	for(int i = 0; i < tocam_juntos; i++)
	{
		cin >> par1 >> par2 >> nivel;
		matriz[par1][par2] = nivel;
		matriz[par2][par1] = nivel;
	}

	// Analiso os tres musicos com maior afinidade
	for(int a = 1; a <= musicos; a++)
	{
		for(int b = 1; b <= musicos; b++)
		{	
			for(int c = 1; c <= musicos; c++)
			{
				if(a != b and a != c and c != b)
				{
					total_temp = matriz[a][b] + matriz[a][c] + matriz[b][c];

					if(total_temp > total)
					{
						total = total_temp;
						banda[0] = a; banda[1] = b; banda[2] = c;
					} // enf if
				}
			} // end for c
		} // end for b
	} // end for a
	
	for(int j = 0; j < 3; j++) 
	{
		cout << banda[j];
		if(j != 2) cout << " ";
	}

	cout << endl;

	return 0;
}
