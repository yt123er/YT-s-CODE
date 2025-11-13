#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame(void);

int main(void) {
	srand(time(NULL));
	guessGame();
}



void guessGame(void) {
	unsigned int number;
	unsigned int i;
	char c = 'y';


	while (c == 'y') {
		printf("I have a number between 1 and 100.""Can you guess my number?\n");
		printf("Please type your first guess.\n");
		scanf("%u", &number);
		i = 1 + (rand() % 100);
		while (number != i) {
			if (number > i)
				printf("Too high.Try again\n");
			else
				printf("Too low.Try again\n");
			scanf("%u", &number);
		}
		puts("Excllent! You guessed the number!");
		printf("Would you like to play again ? (y or n)");

		scanf(" %c", &c);//注意%c前面要加空格以清除前面留在缓冲区的空白字符（空格、换行、制表符等等）

	}

}