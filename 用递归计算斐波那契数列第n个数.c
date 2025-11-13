#include <stdio.h>

unsigned long int fibonacci(unsigned int a);


int main(void) {
	unsigned int integer;

	printf("Enter an integer :");
	scanf("%u", &integer);

	printf("%u", fibonacci(integer));

}



unsigned long int fibonacci(unsigned int a) {

	if (a == 1 || a == 0) {
		return a;
	} else
		return fibonacci(a - 1) + fibonacci(a - 2);

}
