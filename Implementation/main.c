#include <stdio.h>
#include <stdlib.h>
#include "prio.h"

int main()
{
	struct FP P;
	P = prio_creer_vide();		 prio_affiche(P);
	P = prio_inserer(P, 1, 102); prio_affiche(P);
	P = prio_inserer(P, 2, 12); 
	P = prio_inserer(P, 3, 48); 
	P = prio_inserer(P, 4, 36); 
	P = prio_inserer(P, 5, 12); 
	P = prio_inserer(P, 6, 12); 
	P = prio_inserer(P, 7, 12); prio_affiche(P);

	struct elem e;
	printf("### %d ###\n", P.nb_elem);
	e = prio_extraire(&P); printf("%d %d\n", e.id, e.prio);
	printf("### %d ###\n", P.nb_elem);
	prio_affiche(P);
	e = prio_extraire(&P); printf("%d %d\n", e.id, e.prio);
	printf("### %d ###\n", P.nb_elem);
	prio_affiche(P);
	e = prio_extraire(&P); printf("%d %d\n", e.id, e.prio);
	printf("### %d ###\n", P.nb_elem);
	prio_affiche(P);
	e = prio_extraire(&P); printf("%d %d\n", e.id, e.prio);

	exit(0);
}
