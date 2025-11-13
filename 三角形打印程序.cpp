#include <stdio.h>

int main(void) {

	for (unsigned int i = 1; i <= 10; i++) {
		for (unsigned int j = 1; j <= i; j++) {
			printf("%s", "*");
		}
		printf("\n");
	}

	printf("\n");

	for (unsigned int i = 1; i <= 10; i++) {
		for (unsigned int j = 10; j >= i; j--) {
			printf("%s", "*");
		}
		printf("\n");
	}

	printf("\n");

	for (unsigned int i = 1; i <= 10; i++) {
		for (unsigned int k = 1; k < i; k++)
			printf("%s", " ");
		for (unsigned int j = 10; j >= i; j--) {
			printf("%s", "*");
		}
		printf("\n");
	}

	printf("\n");

	for (unsigned int i = 1; i <= 10; i++) {
		for (unsigned int k = 10; k > i; k--)
			printf("%s", " ");
		for (unsigned int j = 1; j <= i; j++) {
			printf("%s", "*");
		}
		printf("\n");

	}
}