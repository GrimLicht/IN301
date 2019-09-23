#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {
	int x,a;
	
	srand(getpid());
	for(x = 0; x < 10000; x++) {
		a = rand() % 1000;
		printf("%3d\n", a);
	}
	return 0;
}
