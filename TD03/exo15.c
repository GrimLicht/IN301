#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define N 10

int* alloue() 
{
	int* T;
	T = malloc( N * sizeof(int) );
	
	if(T == NULL)
	{
		fprintf(stderr,"Pb alloc memory\n");
		exit(1);
	}
	
	srandom(getpid());
	for(int i = 0; i < N; i++)
		T[i] = 1 + random() % 20;
	
	return(T);
}

void affiche(int* T)
{
	int i;
	
	for(i = 0; i < N; i++)
	{
		printf("%3d", T[i]);
	}
	printf("\n");
}

long long int produit(int* T)
{	
	long long int prod;
	prod = 1;
	int i;
	for (i = 0; i < N; i++)
	{
		prod = prod * T[i];
		printf("i = %d prod = %lld\n", i, prod);
	}
	
		
	return prod;
}

int min_tab(int *T)
{
	int i, res;
	
	res = T[0];
	
	for(i = 1; i < N-1; i++)
	{
		if(T[i] < res)
			res = T[i];
	}
	printf("Valeur minimale du tableau : %d\n", res);
	return res;
}

void decal(int* T)
{
	int i;
	
	for(i = N - 1 ; i > 0 ; i--)
	{
		T[i] = T[i - 1];
	}
	affiche (T);
}

int* alloue_tri()
{
	
	int* T;
	T = malloc( N * sizeof(int) );
	
	if(T == NULL)
	{
		fprintf(stderr,"Pb alloc memory\n");
		exit(1);
	}
	
	int i;
	srandom(getpid());
	T[0] = random() % 10;
	for(i = 1; i < N; i++)
		T[i] = T[i-1] + (random()%10);
	
	return(T);
}

void insere_tri(int *T, int val)
{
	int i = N - 1;
	while (T[i - 1] > val)
	{
		T[i] = T[i-1];
		i--;
	} 
	T[i] = val;
}

void inverse()
{
}

void supp()
{
}

void libere()
{
}

int main(int argc, char** argv) 
{
	int* T;
	T = alloue();
	
	affiche(T);
	produit(T);
	min_tab(T);
	decal(T);
	free(T);
	
	printf("New T\n");
	T = alloue_tri();
	affiche(T);
	insere_tri(T, 0);
	affiche(T);
	
	
	
	free(T);
	exit(0);
}
