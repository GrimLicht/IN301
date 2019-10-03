#include <stdio.h>
#include <stdlib.h>
#include "constante.h"

void ecrire() 
{
	FILE *F;
	F = fopen(NOMFIC,"w");
	srand(0);
	for(int i = 0 ; i < N ; i++ ) 
	{
		int val;
		//Génération d'une valeur aléatoire
		val = rand() %MAX; 
		// Ecriture dans le fichier
		fprintf(F, "%6d\n", val);
	}
	fclose(F);
}

int main() 
{
	ecrire();
	return 0;
}
