#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define DOTS 10
#define SEC 1

int main(int argc, char *argv[]) {
	int a,b,c,i;

	printf("Vlozte prvni hodnotu\n");
	scanf("%i", &a);
	printf("Vlozte druhou hodnotu\n");
	scanf("%i", &b);
	printf("%i + %i = ", a, b);

	for( i=0; i<DOTS; i++ ) {
		printf(".");
		fflush(stdout);
		sleep(SEC);
	}

	c = a+b;
	printf("%i\n", c);
	return EXIT_SUCCESS;
}
