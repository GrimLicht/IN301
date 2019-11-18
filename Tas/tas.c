#include <stdlib.h>
#include <stdio.h>
#include "tas.h"

TAS tas_creer()
{
	TAS T;
	
	T = malloc(sizeof(struct tas));
	
	if(T == NULL)
		exit(1);
	
	T->n = 0;
	T->date = 0;
	T->t = malloc((MAXELEM+1)*sizeof(struct tas));
	if(T->t == NULL) exit(2);
	
/*	TEST 
	T-> n = 3;
	T->date = 1;
	T->t[1].id = 100;
	T->t[1].prio = 66;
	T->t[1].date = 0;
	
	T->t[2].id = 101;
	T->t[2].prio = 2;
	T->t[2].date = 0;
	
	T->t[3].id = 102;
	T->t[3].prio = 11;
	T->t[3].date = 0;*/

	
	return T;
}

int pere_est_sup(TAS T, int i)
{
	int p = i/2;
	if (T->t[p].prio > T->t[i].prio)
		return 1;
	if (T->t[p].prio < T->t[i].prio)
		return 0;

	return T->t[p].date < T->t[i].date;
}

void swap_avec_pere(TAS T, int i)
{
	int p = i/2;
	ELEM tmp = T->t[i];
	T->t[i] = T->t[p];
	T->t[p] = tmp;
}

TAS reorganise(TAS T, int i)
{
	int p = i/2;
	if(i==1) return T;
	if (pere_est_sup(T,i)) return T;
	swap_avec_pere(T,i);
	
	return reorganise(T,p);
}

TAS tas_inserer(TAS T, int id, int prio)
{
	if (T->n >= MAXELEM) exit(3);
	
//1.on rajoute nvl elem à la fin	
	(T->n)++;
	T->t[T->n].id = id;
	T->t[T->n].prio = prio;
	T->t[T->n].date = T->date;
	(T->date)++;
	
//2. on reorganise
	T = reorganise(T,T->n);
	
	return T;
}

ELEM tas_extraire(TAS T)
{
	ELEM e = T->t[1];
	
	T->t[1] = T->t[T->n];
	(T->n)--;
	
	return e;
}

int tas_vide(TAS T)
{
	if (T->n == 0) return 1;
		else return 0;
}

void tas_affiche(TAS T)
{
	printf("###\n");
	printf("nbelem = %d\n", T->n);
	printf("date = %d", T->date);
	int i;
	for (i=1; i<= T->n; i++)
		elem_affiche(T->t[i]);
	printf("\n###\n");	
}	

void elem_affiche(ELEM e)
{
	printf(" [");
	printf("%d", e.id);
	printf(" %d", e.prio);
	printf(" %d", e.date);
	printf("]");
	
}

void afficher_elem(ELEM e)
{
	printf("*** ");
	printf("[ %d %d %d ]", e.id, e.prio, e.date);
	printf(" ***\n");
}
