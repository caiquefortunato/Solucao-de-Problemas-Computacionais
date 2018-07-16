#include <stdio.h>

int main()
{
	int n, i, x, total;
	total = 0;
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		total += x;
	}

	printf("%d\n", total); 

	return 0;
}
