#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void getCommands(int commands[][2]);
void movePen(bool down, int a[][50], int dir, int dist);
void printArray(int a[][50]);


int main(void) {
	int commandArray[MAX][2] = {0};
	getCommands(commandArray); //获取指令数组
	int count = 0;
	int command = commandArray[count][0];
	int floor[50][50] = {0};  //坐标数组
	int penDown = false;
	int direction = 0;
	int distance;

	while (command != 9) {
		command = commandArray[count][0]; //要在循环内位command赋一次值，要不然command的值会一直停留在定义时的值，导致死循环。
		switch (command) {
			case 1:
				penDown = false;
				break;
			case 2:
				penDown = true;
				break;
			case 3:
				direction = (direction + 1) % 4;
				break;
			case 4:
				direction = (direction + 3) % 4;
				break;
			case 5:
				distance = commandArray[count][1];
				movePen(penDown, floor, direction, distance);
				break;
			case 6:
				printArray(floor);
				break;
		}
		count++;
	}
	return 0;
}

void getCommands(int commands[][2]) {

	for (int i = 0; i < MAX; i++) {
		printf("Enter command(9 to end input): ");
		scanf("%d", &commands[i][0]);

		if (commands[i][0] == 9) {
			break;
		}
		if (commands[i][0] == 5) // 只有5需要第二个数作为distance
			scanf(",%d", &commands[i][1]);

	}
}

void movePen(bool down, int a[][50], int dir, int dist) {
	static int x = 0, y = 0;
	if (down) {

		if (dir == 0) {
			for (int i = 0; i < dist && x < 50; i++) {
				a[y][x] = 1;
				x += 1;
			}
		}
		if (dir == 1) {
			for (int i = 0; i < dist && y < 50; i++) {
				a[y][x] = 1;
				y += 1;

			}
		}
		if (dir == 2) {
			for (int i = 0; i < dist && x >= 0; i++) {
				a[y][x] = 1;
				x -= 1;

			}
		}
		if (dir == 3) {
			for (int i = 0; i < dist && y >= 0; i++) {
				a[y][x] = 1;
				y -= 1;

			}
		}


	}
}


void printArray(int a[][50]) {
	printf("The drawing is: \n");
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (a[i][j] == 1)
				printf("%c", '*');
			else
				printf("%c", ' ');
		}
		puts("");
	}
}
