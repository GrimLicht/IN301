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

struct liste *inserer_fin_iter (struct liste *l, int val)
{
	// création d'élément
	struct liste * e;
	e = malloc(sizeof(struct liste));
	if(!e)
	{
		fprintf(stderr,"Cannot malloc\n");
		exit(2);
	}
	
	e->val = val;
	e->suiv = NULL;
	if (l==NULL) return e;
	
	
	struct liste * f = l;
	
	while (f->suiv != NULL)
	{
		f = f->suiv;
	}
	f->suiv = e;
	
	
	return l;
}

struct liste *inserer_fin_rec(struct liste *l, int val)
{
	if (l==NULL)
	{
		struct liste * e = malloc(sizeof(struct liste));
		if(!e)
		{
			fprintf(stderr,"Cannot malloc\n");
			exit(2);
		}
		e->val = val;
		e->suiv = NULL;
		return e;
	}
	l->suiv = inserer_fin_rec(l->suiv,val);
	return l;
}

struct liste *inserer_trie_iter (struct liste *l, int val)
{	
	return l; // trop de cas particuliers à gérer
}

struct liste *inserer_trie_rec (struct liste *l, int val)
{
	if ((l==NULL) || (val < l->val)) 
	{
		struct liste *e = malloc(sizeof(struct liste));
		if(!e) exit(2);
		e->val = val;
		e->suiv = l;
		return e;
	}
	
	l->suiv = inserer_trie_rec(l->suiv,val);
	return l;
}

struct liste *retourner (struct liste *l)
{
	struct liste * l2 = NULL;
/*	while (l != NULL)
	{
		l2 = inserer_deb(l2,l->val);
		l = supprimer_deb(l);
	}*/
	
	while (l!=NULL)
	{
		struct liste *e;
		e = l;
		l = l->suiv;
		e->suiv = l2;
		l2 = e;
	}
	return l2;
}

struct liste *concat_iter (struct liste *l1, struct liste *l2)
{
	if (l1==NULL) return l2;
	struct liste *p = l1;
	while (p->suiv) p = p-> suiv;
	p->suiv = l2;
	
	return l1;
}

struct liste *concat_rec (struct liste *l1, struct liste *l2)
{
	if (l1==NULL) return l2;
	l1->suiv = concat_rec(l1->suiv,l2);
	return l1;
}

struct liste *fusion (struct liste *l1, struct liste *l2)
{
/* ALGO 1 : en n²
 	while (l2)
	{
		l1 = inserer_trie_rec(l1, l2->val);
		l2 = supprimer_deb(l2);
	}
	return l1;
*/

//ALGO 2 en n
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	struct liste *deb;
	struct liste *fin;
	if (l1->val < l2->val) 
	{
		deb = fin = l1;
		l1 = l1->suiv;
	}
		else
		{
			deb = fin = l2;
			l2 = l2->suiv;
		}
	while (l1 && l2) 
	{
		if (l1->val < l2->val) 
		{
			fin->suiv = l1;
			l1 = l1->suiv;
		}
			else
			{
				fin->suiv = l2;
				l2 = l2->suiv;
			}
		fin = fin->suiv;
		fin->suiv = NULL;
	}
	if (l1 == NULL) fin->suiv = l2;
		else fin->suiv = l1;
		
	return deb;
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
	if(l==NULL) return l;
	struct liste *e = l;
	l = l->suiv;
	free(e);
	return l;
}
