#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verif(char* s)
{
	int j = 0;
	
	if(s[j] == '-')
		j++;
	if(!isdigit(s[j]))
		return 0;
	while(isdigit(s[j]))
		j++;
	switch(s[j])
	{
		case '.': j++; break;
		case '\0': return 1; break;
		default : return(0);
	}
	if(!isdigit(s[j]))
		return(0);
	while(isdigit(s[j]))
		j++;
	if(s[j] == '\0') 
		return 1;
	else 
		return 0;
}

int main( int argc, char** argv)
{
	int i;
	float res = 0.0;
	printf("argc = %d\n", argc);
	
	i = 1;
	while(i<argc && verif(argv[i]))
		i++;
	if(i < argc)
	{
		printf("La chaîne de caractère %s n'est pas un nombre flottant\n", argv[i]);
		exit(0);
	}
	
	for(i=1 ; i<argc ; i++)
		res += atof(argv[i]);
		
	printf("%.2f\n", res);
	
	exit(0);
}
