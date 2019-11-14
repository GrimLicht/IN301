#define TAILLE_MAX 1000

struct elem
{
	int id;
	int prio;
	int date;
};

struct tas
{
	int n; //nb d'elem
	int date;
	struct elem *t;
}; typedef struct tas* TAS;

struct tas tas_creer();

void tas_inserer(TAS t, int id, int prio);

struct elem tas_extraire(TAS t);

void elem_affiche(struct elem e);
