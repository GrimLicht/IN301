#include "prio.h"
#include <stdio.h>
#include <stdlib.h>


struct FP prio_creer_vide()
{
	struct FP P;
	P.nb_elem = 0;
	P.premier = NULL;
	return P;
}

int prio_est_vide(struct FP P)
{
	return(!P.nb_elem);
}

struct liste* inserer_trier(struct liste* l, struct elem e)
{
	if ((l == NULL) || (l->e.prio < e.prio))
	{
		struct liste* le = malloc(sizeof(struct liste));
		if (le == NULL) exit(1);
		le->e = e;
		le->suiv = l;
		return le;
	}
	l->suiv = inserer_trier(l->suiv, e);
	return l;
}

struct FP prio_inserer(struct FP P, int id, int prio)
{
	struct elem e;
	e.id = id;
	e.prio = prio;
	(P.nb_elem)++;
	P.premier = inserer_trier (P.premier, e);
	
	return P;
}

struct elem prio_extraire(struct FP* P)
{
	if (P->nb_elem == 0) exit(2);
	struct elem e = P->premier->e;
	struct liste* l = P->premier;
	(P->nb_elem)--;
	P->premier = P->premier->suiv;
	free(l);
	return e;
}

void prio_affiche(struct FP P)
{
	printf("%d\n",P.nb_elem);
	struct liste* l = P.premier;
	while (l)
	{
		printf(" %3d %3d |",l->e.id, l->e.prio);
		l = l-> suiv;
	} 
	printf("\n");
}
