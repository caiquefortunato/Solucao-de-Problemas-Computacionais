#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	int buracos, flag;
	double gx, gy, cx, cy, ax, ay, cordx, cordy, calc1, calc2;
	
	while(scanf("%d %lf %lf %lf %lf", &buracos, &gx, &gy, &cx, &cy) != EOF)
	{
		flag = 0;
		for(int i = 0; i < buracos; i++)
		{
			scanf("%lf %lf", &ax, &ay);
			

			calc1 = 4* ((pow((gx - ax), 2)) + (pow((gy - ay), 2)));
			calc2 = (pow((cx - ax), 2) + pow((cy - ay), 2));
			
			if(calc1 <= calc2)
			{
				flag += 1;
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", ax, ay);
			}
		} // fim da leitura dos dados
	
		if(!flag) printf("The gopher cannot escape.\n");
	
	} // Fim dos casos de teste

		
	return 0;
}
