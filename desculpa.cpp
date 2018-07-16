#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int mochila(int c, int f, int caractere[], int desculpa[])
{
	int result, mochila[f + 1][c + 1];
	
	//for(int i = 1; i < f; i++)
	//	for(int j = 0; j < c; j++)
	//		mochila[i][j] = 0;

	for(int i = 0; i <= f; i++)
	{
		for(int j = 0; j <= c; j++)
		{
			if(i == 0 or j == 0) mochila[i][j] = 0;
			else if(caractere[i - 1] > j)
				mochila[i][j] = mochila[i - 1][j];
			else
				mochila[i][j] = max(mochila[i - 1][j], mochila[i - 1][j - caractere[i - 1]] + desculpa[i - 1]);
		} // fim do segundo for
	} // fim do primeiro for

	result = mochila[f][c];
	return result;
}

int main()
{
	int c, f, teste, result;
	int caractere[1001], desculpa[1001];

	while(true)
	{
		scanf("%d %d", &c, &f);
		teste += 1;
		if(c == 0 and f == 0) break;

		for(int i = 0; i < f; i++)
			scanf("%d %d", &caractere[i], &desculpa[i]);

		result = mochila(c, f, caractere, desculpa);
		printf("Teste %d\n", teste);
		printf("%d\n\n", result);
	} // fim do while

	return 0;
}
