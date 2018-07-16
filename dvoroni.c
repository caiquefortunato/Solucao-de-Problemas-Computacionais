#include <cstdio>
#include <cmath>

using namespace std;

typedef struct Pontos
{int x, y, z;} Pontos;

int vet1[3], vet2[3], vet3[3];

// Calcula vetores P, Q, R baseada nos pontos
void calcula_vetores(Pontos p[]) 
{	
	// Preenchendo o vetor 1 = B - A
	vet1[0] = p[1].x - p[0].x; 
	vet1[1] = p[1].y - p[0].y; 
	vet1[2] = p[1].z - p[0].z;
	
	// Preenchendo o vetor 2 = C - A
	vet2[0] = p[2].x - p[0].x; 
	vet2[1] = p[2].y - p[0].y; 
	vet2[2] = p[2].z - p[0].z;
	
	// Preenchendo o vetor 3 = D - A
	vet3[0] = p[3].x - p[0].x; 
	vet3[1] = p[3].y - p[0].y; 
	vet3[2] = p[3].z - p[0].z;
}

// Realiza o calculo do determinante
int calcula_determinante()
{
	int soma_ida = 0, soma_volta = 0;
	double determinante;
	
	soma_ida += (vet1[0] * vet2[1] * vet3[2]);
	soma_ida += (vet2[0] * vet3[1] * vet1[2]);
	soma_ida += (vet3[0] * vet1[1] * vet2[2]);
	
	soma_volta += (vet1[2] * vet2[1] * vet3[0]);
	soma_volta += (vet2[2] * vet3[1] * vet1[0]);
	soma_volta += (vet3[2] * vet1[1] * vet2[0]);
	
	determinante = abs(soma_ida - soma_volta);
	//printf("%.6lf", determinante);
	
	printf("%.6lf\n", determinante / 6);
}

int main()
{
	int testes, determinante;
	double volume;
	Pontos p[4]; // vetor de struct com as coordenadas dos pontos
	
	scanf("%d", &testes);
	
	for(int i = 0; i < testes; i++)
	{
		for(int j = 0; j < 4; j++)
			scanf("%d %d %d", &p[j].x, &p[j].y, &p[j].z);
		
		calcula_vetores(p);
		calcula_determinante();
		
	} // fim do for dos casos de teste
	
	return 0;
}