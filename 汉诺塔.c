#include <stdio.h>


void tower(int c, int start, int end, int temp);


int main(void) {
	printf("%s", "Enter the starting number of disks: ");
	int  n;
	scanf("%d", &n);


	tower(n, 1, 3, 2);
}


void tower(int c, int start, int end, int temp) {
	if (1 == c) {
		printf("% d --> % d\n", start, end);
	} else {
		tower(c - 1, start, temp, end);
		tower(1, start, end, end);
		tower(c - 1, temp, end, start);
	}
}
