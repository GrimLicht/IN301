#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>

// #####
// 1. Génération, suppression et affichage de tableaux
// #####
TABINT gen_alea_tabint (int N, int K) {
	TABINT T;

	T.N = N;
	T.T = malloc(N * sizeof(int));
	
	if(T.T == NULL) 
	{
		fprintf(stderr, "Pb alloc de memoire\n");
		exit(1);
	}
	
	int i;
	for (i = 0; i < N; i++)
	{
		T.T[i] = rand() % K;
	}
	
	return T;
}

TABINT sup_tabint (TABINT T) 
{
	
	free(T.T);
	
	T.N = 0;
	T.T = NULL;
	
	return T;
}

void aff_tabint (TABINT T) 
{
	int i;
	for (i = 0; i < T.N; i++)
	{
		printf(" %3d ", T.T[i]);
	}
	printf("\n");
}

// #####
// 2. Manipulation des valeurs du tableau
// #####

// Echange la case i et la case i+1 si la case i est > à la case i+1
void ech_tabint (TABINT T, int i) 
{
// verif de la cohérence de i
	if ((i<0) || (i>T.N-2))
	{
		fprintf(stderr,"Dans fonction ech_tabint : i = %d N = %d\n",i,T.N);
		exit(2);
	}
	NB_COMP++;
	if (T.T[i]> T.T[i+1])
	{
		NB_ECH++;
		int tmp = T.T[i];
		T.T[i] = T.T[i+1];
		T.T[i+1] = tmp;
	}
}

void scan_ech_tabint (TABINT T, int fin)  
{
	int i;
	for (i=0; i<fin-1 ; i++)
	{
		ech_tabint(T,i);
	}

}

