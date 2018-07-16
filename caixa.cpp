#include <cstdio>
#include <cmath>

int main()
{
	int a, b;
	double delta, x1, x2, vol1, vol2;
	
	while(1)
	{
		scanf("%d %d", &a, &b);
		if(a == 0 and b == 0) break;
		
		delta = (pow((4*a + 4*b), 2) - 48*a*b);
		
		x1 = ((4*a + 4*b) + sqrt(delta)) / 24;
		x2 = ((4*a + 4*b) - sqrt(delta)) / 24;
		 
		vol1 = (a - 2*x1) * (b - 2*x1) * x1;
		vol2 = (a - 2*x2) * (b - 2*x2) * x2;
		
		if(vol1 > vol2)
			printf("%.4lf %.4lf\n", x1, vol1);
		else if(vol1 < vol2)
			printf("%.4lf %.4lf\n", x2, vol2);
							
	}

	return 0;
}
