
#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>


void tri_bulle(TABINT T) 
{
	NB_COMP = 0;
	NB_ECH = 0;
	int i;
	for(i = T.N-1 ; i > 0 ; i--)
	{
		scan_ech_tabint(T,i);
	}
	printf("NB_COMP = %d\n",NB_COMP);
	printf("NB_ECH = %d\n",NB_ECH);	
}

struct stat stat_moy(int N, int A)
{
	struct stat S;
	S.N = N;
	long long int nb_tot_comp = 0;
	long long int nb_tot_ech  = 0;
	int nbexp;
	for (nbexp=0 ; nbexp < A ; nbexp++)
	{
		TABINT T;
		T = gen_alea_tabint (10, 100);
		tri_bulle(T);
		nb_tot_comp += NB_COMP;
		nb_tot_ech += NB_ECH;
		aff_tabint(T);
		T = sup_tabint (T);
	}
	S.nb_moy_comp = (float)nb_tot_comp/(float)A;
	S.nb_moy_ech = (float)nb_tot_ech/(float)A;
	return S;
}

int main() {
	struct stat S;
	S = stat_moy(10, 4);
	printf("%d %f %f\n", S.N, S.nb_moy_comp, S.nb_moy_ech);
	
	
	// Le code ci-dessous est provisoire, juste pour faire marche l'enchainement du Makefile
	FILE *F;
	F = fopen("test_tri_bulle.data","w");
	fprintf(F,"   10           45.00           21.97\n");
 	fprintf(F,"   12           66.00           33.08\n");
 	fprintf(F,"   14           91.00           46.35\n");
 	fprintf(F,"   16          120.00           61.08\n");
 	fprintf(F,"   19          171.00           85.71\n");
 	fprintf(F,"   22          231.00          115.62\n");
 	fprintf(F,"   26          325.00          162.21\n");
	fclose(F);
	// Fin du code provisoire
	exit(0);
}
