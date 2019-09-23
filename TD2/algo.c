#include <stdio.h>
#include <stdlib.h>
#include "constante.h"

int T[N];

void lecture()
{
	int j;
	FILE *F;
	F = fopen(NOMFIC,"r");
	
	for(int i = 0 ; i < N ; i++ )
	{
		fscanf(F,"%d", &j);
		T[i] = j;

		//printf("i = %d, T[i] = %d\n", i, T[i]);
	}
	
	fclose(F);
}

void ecriture_test()
{
	FILE *F;
	F = fopen(NOMFICverif,"w");
	for(int i = 0 ; i < N ; i++ )
	{
		fprintf(F,"%6d\n", T[i]);
	}
	fclose(F);
} 

int recherche(int x)
{
	int found, i;
	found = 0;
	i = 0;
	while((found==0) && (i<N))
	{
		if (T[i] == x)
			found = 1;
		else 
			found = 0;
			
		i++;
	}
	printf("La fonction a fait %d comparaisons ", i);
	return(found);
}

int stat_recherche(int x)
{
	int found, i;
	found = 0;
	i = 0;
	while((found==0) && (i<N))
	{
		if (T[i] == x)
			found = 1;
		i++;
		if (found == 1)
			return(i);
	}
	return(i);
}

int main() 
{
	lecture();
	ecriture_test();
//	printf("Is x here : %d\n",recherche(0));
//	printf("x is here : %d times\n",stat_recherche(0));
	
	int j;
	int somme = 0;
	for ( j = 0 ; j<10000 ; j++)
	{
		int val = rand() % (5*MAX);
		int nb_comp = stat_recherche(val);
		some += nb_comp;
	}
	float moyenne;
	moyenne = (float)somme/10000.0;
	printf("Moyenne = %.2f\n",moyenne);
	
	
	
	exit(0);
}
