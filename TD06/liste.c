#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void affiche_iter (struct liste *l)
{
		printf("###\n");
	while(l)
	{
		printf(" %d\n", l->val);
		l = l->suiv;
	}
	
		printf("#\n");
}

void affiche_rec (struct liste *l)
{
	if (!l) return;
	printf(" %d", l->val);
	affiche_rec(l->suiv);
	

}

struct liste *inserer_deb(struct liste *l, int val)
{
	struct liste *e;
	e = malloc(sizeof(struct liste));
	if(!e)
	{
		fprintf(stderr,"Cannot malloc\n");
		exit(1);
	}
	e->val = val;
	e->suiv = l;
	
	return e;
}

void inserer_deb2 (struct liste **l, int val)
{
	struct liste *e;
	e = malloc(sizeof(struct liste));
	if(!e)
	{
		fprintf(stderr,"Cannot malloc\n");
		exit(1);
	}
	e->val = val;
	e->suiv = *l;
	*l = e;
}


int nb_elem_iter (struct liste *l)
{
	int cmpt = 0;
	while(l)
	{
		l = l->suiv;
		cmpt++;
	}
	
	return cmpt;
}

int nb_elem_rec (struct liste *l)
{
	if(!l) return 0;
	return (1 + nb_elem_rec(l->suiv));
}

int est_present_iter (struct liste *l, int val)
{
	while(l)
	{
		if (l->val == val)
			return 1;
		l = l->suiv;
	}
	
	return 0;
}

int est_present_rec (struct liste *l, int val)
{
	if(!l) return 0;
	
	if (l->val == val) return 1;
	else 
		return est_present_rec(l->suiv, val);
}

struct liste *supprimer_deb (struct liste *l)
{
	return l;
}
