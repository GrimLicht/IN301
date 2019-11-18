#include "tas.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	TAS T;
	T = tas_creer();
	tas_affiche(T);
	T = tas_inserer(T,103,11);
	T = tas_inserer(T,104,22);	
	T = tas_inserer(T,105,15);	
	T = tas_inserer(T,106,3);	
	T = tas_inserer(T,107,44);	
	T = tas_inserer(T,108,88);	
	T = tas_inserer(T,109,67);	
	T = tas_inserer(T,110,4);
//	printf("%d\n", tas_vide(T));
	
	tas_affiche(T);
	afficher_elem(tas_extraire(T));	
	tas_affiche(T);
	
	exit(0);
}
