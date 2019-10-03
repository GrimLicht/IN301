#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char** argv)
{
	int i;
	double a = 0.0;
	printf("argc = %d\n", argc);
	for(i=1 ; i<argc ; i++)
	{
		a += atof(argv[i]);
	}
	printf("%f\n", a);
	return 0;
}
