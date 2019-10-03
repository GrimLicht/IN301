#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	printf("Size of int = %ld\n", sizeof(int));
	printf("Size of char = %ld\n", sizeof(char));
	printf("Size of double = %ld\n", sizeof(double));
	printf("Size of char* = %ld\n", sizeof(char*));
	printf("Size of void* = %ld\n", sizeof(void*));
	printf("Size of int* = %ld\n", sizeof(int*));
	printf("Size of double* = %ld\n", sizeof(double*));
	printf("Size of int** = %ld\n", sizeof(int**));
	printf("Size of int[10] = %ld\n", sizeof(int[10]));
	printf("Size of char[7][3] = %ld\n", sizeof(char[7][3]));
//	printf("Size of int[] = %ld\n", sizeof(int[]));
	return 0;
}
