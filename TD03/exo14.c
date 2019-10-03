#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void echange (int *a, int *b) {
int c;


c = 0;

c = *a;
*a = *b;
*b = c;
}

int main() {
int a, b;

a = 7;
b = 2;

printf("a = %d\n", a);
printf("b = %d\n\n", b);
echange(&a,&b);
printf("a = %d\n", a);
printf("b = %d\n\n", b);
}
