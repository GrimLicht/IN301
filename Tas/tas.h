#define MAXELEM 1024
struct elem
{
	int id;
	int prio;
	int date;
}; typedef struct elem ELEM;

struct tas
{
	int n; //nb d'elem
	int date;
	struct elem *t;
}; typedef struct tas* TAS;

TAS tas_creer();

TAS tas_inserer(TAS T, int id, int prio);

ELEM tas_extraire(TAS t);

int tas_vide(TAS T);

void tas_affiche(TAS T);

void elem_affiche(ELEM e);

void afficher_elem(ELEM e);
