/*
Autor: Caíque Bruno Fortunato
Solução do problema: 11152 - Colorful Flowers
Colorful Flowers (https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2093)
Código: Aceito
*/

#include <bits/stdc++.h>
#define PI acos(-1)

using namespace std;

int main()
{
	double a, b, c;
	double raio_inscrito, area_triangulo, raio_circunscrito;
	double area_ci, area_cc, s;
	
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		// Semi-perimetro
		s = (a + b + c) / 2;
		// Forumula de Heron
		area_triangulo = sqrt(s * (s - a)*(s - b)*(s - c));
		// Formula do circulo inscrito
		raio_inscrito = area_triangulo / s;
		// Formula do circulo circunscrito
		raio_circunscrito = (a*b*c) / (4 * area_triangulo);
		
		area_ci = pow(raio_inscrito, 2) * PI;
		area_cc = (pow(raio_circunscrito, 2) * PI) - area_triangulo;
		area_triangulo -= area_ci;
		
		printf("%.4lf %.4lf %.4lf\n", area_cc, area_triangulo, area_ci);
		
	} // fim do while dos casos de teste
	
	return 0;
}
