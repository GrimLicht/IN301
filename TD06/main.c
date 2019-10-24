#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main()
{
	struct liste *l1 = NULL;
	
	affiche_rec(l1); printf("\n#\n");
	l1 = inserer_trie_rec(l1, 12); 
	l1 = inserer_trie_rec(l1, -3); 
	l1 = inserer_trie_rec(l1, 20); 
	l1 = inserer_trie_rec(l1, 489);
	l1 = inserer_trie_rec(l1, -57);
	affiche_rec(l1); printf("\n#\n");
	
	struct liste *l2 = NULL;
	l2 = inserer_trie_rec(l2, 45); 
	l2 = inserer_trie_rec(l2, -68); 
	l2 = inserer_trie_rec(l2, -88); 
	l2 = inserer_trie_rec(l2, 2222);
	l2 = inserer_trie_rec(l2, -666);
	affiche_rec(l2); printf("\n#\n");
	
	struct liste* l;
	l = fusion(l1,l2);
	affiche_rec(l); printf("\n#\n");
	
	
	
/*	printf("Nb elem rec = %d\n", nb_elem_rec(l));
	printf("Est présent -3 = %d\n", est_present_iter(l, -3));
	printf("Est présent rec 17 = %d\n", est_present_rec(l, 17));
*/
	
	
	
	exit(0);
}
