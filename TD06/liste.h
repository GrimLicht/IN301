struct liste {
	int val; // Valeur stockée
	struct liste *suiv; // Pointeur vers le suivant
};

void affiche_iter (struct liste *l);
void affiche_rec (struct liste *l);

int nb_elem_iter (struct liste *l);
int nb_elem_rec (struct liste *l);

int est_present_iter (struct liste *l, int val);
int est_present_rec (struct liste *l, int val);

struct liste *inserer_deb (struct liste *l, int val);
void inserer_deb2 (struct liste **l, int val);
struct liste *supprimer_deb (struct liste *l);

struct liste *inserer_fin_iter (struct liste *l, int val);
struct liste *inserer_fin_rec (struct liste *l, int val);

struct liste *inserer_trie_iter (struct liste *l, int val);
struct liste *inserer_trie_rec (struct liste *l, int val);

struct liste *retourner (struct liste *l);
struct liste *concat_iter (struct liste *l1, struct liste *l2);
struct liste *concat_rec (struct liste *l1, struct liste *l2);
struct liste *fusion (struct liste *l1, struct liste *l2);
