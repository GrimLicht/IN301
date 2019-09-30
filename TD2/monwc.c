#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp_carac(FILE *F)
{
	int cmp = 0;
	
	while(fgetc(F) != EOF)
		cmp++;
	
	return(cmp);
}

int cmp_ligne(FILE *F)
{
	int cmp = 0;
	char c;
	while((c = fgetc(F)) != EOF)
	{
		if(c == '\n') 
			cmp++;
		}
		return cmp;
	
	return(0);
}

int main(int argc, char** argv)
{
	FILE * F;
	
	
	if((argc != 3) || ((strcmp(argv[1], "-c") != 0) &&
	(strcmp(argv[1], "-l")) != 0))
	{
		printf("Erreur, format attendu :\n");
		printf("%s: -option fichier\n", argv[0]);
		printf("Options : -c ou -l\n");
		exit(0);
	}
	F = fopen(argv[2], "r");
	if(F == NULL)
	{
		printf("Erreur ouverture fichier %s\n", 
		argv[2]);
		
		exit(0);
	}
	
	
	
	if(strcmp(argv[1], "-c") == 0)
	{
		printf(
		"Nombres de caractères du fichier %s: %d\n",
		argv[2], cmp_carac(F));
	}
		
	if(strcmp(argv[1], "-l") == 0)
	{
		printf(
		"Nombres de lignes du fichier %s: %d\n",
		argv[2], cmp_ligne(F));
	}	
	
	fclose(F);
	
	exit(0);
}
