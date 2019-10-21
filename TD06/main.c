#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main()
{
	struct liste *l = NULL;
	affiche_rec(l);
//	l = inserer_deb(l, 12); affiche_rec(l); printf("\n");
//	l = inserer_deb(l, -3); affiche_rec(l); printf("\n");
//	l = inserer_deb(l, 20); affiche_rec(l); printf("\n");
	
	inserer_deb2(&l, 12); affiche_rec(l); printf("\n");
	inserer_deb2(&l, -3); affiche_rec(l); printf("\n");
	inserer_deb2(&l, 20); affiche_rec(l); printf("\n");
	
//	printf("Nb elem = %d\n", nb_elem_iter(l));
	printf("Nb elem rec = %d\n", nb_elem_rec(l));
//	printf("Est présent -3 = %d\n", est_present_iter(l, -3));
//	printf("Est présent 17 = %d\n", est_present_iter(l, 17));
	printf("Est présent rec -3 = %d\n", est_present_rec(l, -3));
	printf("Est présent rec 17 = %d\n", est_present_rec(l, 17));
	printf("Est présent rec 12 = %d\n", est_present_rec(l, 12));
	
	affiche_rec(l); printf("\n");
	l = supprimer_deb (l);
	affiche_rec(l); printf("\n");
	
	exit(0);
}
