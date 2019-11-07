
struct elem
{
	int id;
	int prio;
};

struct liste
{
	struct elem e;
	struct liste* suiv;
//	struct liste* pred;
};

struct FP 
{
	int nb_elem;
	struct liste* premier;
};

struct FP	prio_creer_vide();
int 	 	prio_est_vide(struct FP P);
struct FP	prio_inserer(struct FP P, int id, int prio);
struct elem prio_extraire(struct FP* P);

void	  prio_affiche(struct FP P);
