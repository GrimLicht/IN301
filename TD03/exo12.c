#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	int T[7][3];
	
	printf("              T : %p\n", T);
	printf("Adresse T[0][0] : %p \n", &(T[0][0]));
	printf("Adresse T[0][1] : %p \n", &(T[0][1]));
	printf("Adresse T[0][2] : %p \n", &(T[0][2]));
	printf("Adresse T[1][0] : %p \n", &(T[1][0]));
	printf("Adresse T[1][1] : %p \n", &(T[1][1]));
	
	return 0;
}
