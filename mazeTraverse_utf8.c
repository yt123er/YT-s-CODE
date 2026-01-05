#include <stdio.h>
#include <stdlib.h>

#define DOWN  0 //向下移动
#define RIGHT 1 //向右移动
#define UP    2 //向上移动
#define LEFT  3 //向左移动

#define X_START 2   //起点的x，y值
#define Y_START 0

void mazeTraversal(char maze[12][12], size_t xCoord, size_t yCoord,
                   unsigned int direction);
void printMaze(const char maze[][12]);
int validMove(const char maze[][12], size_t r, size_t c);
int coordsAreEdge(size_t x, size_t y);

int main(void) {
	char maze[12][12] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
		{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
		{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
		{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};

	mazeTraversal(maze, X_START, Y_START, RIGHT);

	return 0;
}

void mazeTraversal(char maze[12][12], size_t xCoord, size_t yCoord, unsigned int direction) {
	if (coordsAreEdge(xCoord, yCoord)) { //先进行边界判断
		maze[xCoord][yCoord] = 'X';
		printf("Successfully traversed the maze\n");
		return;
	}

	maze[xCoord][yCoord] = 'X';

	printMaze(maze);

	if (direction == RIGHT) {
		if (validMove(maze, xCoord + 1, yCoord)) { //右手扶墙
			mazeTraversal(maze, xCoord + 1, yCoord, DOWN);
		} else if (validMove(maze, xCoord, yCoord + 1)) {
			mazeTraversal(maze, xCoord, yCoord + 1, RIGHT);
		} else if (validMove(maze, xCoord - 1, yCoord)) {
			mazeTraversal(maze, xCoord - 1, yCoord, UP);
		} else if (validMove(maze, xCoord, yCoord - 1)) { //后退
			mazeTraversal(maze, xCoord, yCoord - 1, LEFT);
		}
	}

	if (direction == DOWN) {
		if (validMove(maze, xCoord, yCoord - 1)) {
			mazeTraversal(maze, xCoord, yCoord - 1, LEFT);
		} else if (validMove(maze, xCoord + 1, yCoord)) {
			mazeTraversal(maze, xCoord + 1, yCoord, DOWN);
		} else if (validMove(maze, xCoord, yCoord + 1)) {
			mazeTraversal(maze, xCoord, yCoord + 1, RIGHT);
		} else if (validMove(maze, xCoord - 1, yCoord)) { //回退
			mazeTraversal(maze, xCoord - 1, yCoord, UP);
		}
	}

	if (direction == LEFT) {
		if (validMove(maze, xCoord - 1, yCoord)) { //右手扶墙
			mazeTraversal(maze, xCoord - 1, yCoord, UP);
		} else if (validMove(maze, xCoord, yCoord - 1)) {
			mazeTraversal(maze, xCoord, yCoord - 1, LEFT);
		} else if (validMove(maze, xCoord + 1, yCoord)) {
			mazeTraversal(maze, xCoord + 1, yCoord, DOWN);
		} else if (validMove(maze, xCoord, yCoord + 1)) { //回退
			mazeTraversal(maze, xCoord, yCoord + 1, RIGHT);
		}
	}

	if (direction == UP) {
		if (validMove(maze, xCoord, yCoord + 1)) { //右手扶墙
			mazeTraversal(maze, xCoord, yCoord + 1, RIGHT);
		} else if (validMove(maze, xCoord - 1, yCoord)) {
			mazeTraversal(maze, xCoord - 1, yCoord, UP);
		} else if (validMove(maze, xCoord, yCoord - 1)) {
			mazeTraversal(maze, xCoord, yCoord - 1, LEFT);
		} else if (validMove(maze, xCoord + 1, yCoord)) {
			mazeTraversal(maze, xCoord + 1, yCoord, DOWN);
		}
	}

}

void printMaze(const char maze[][12]) { //打印迷宫并实现一步一打印功能
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	puts("");
	printf("Hit return to see next move");
	getchar();  //按下回车以执行下一步
}

int validMove(const char maze[][12], size_t r, size_t c) { //是否能进行有效移动
	if (maze[r][c] == '.' || maze[r][c] == 'X') {
		return 1;
	} else
		return 0;
}

int coordsAreEdge(size_t x, size_t y) { //检查是否到达边缘
	if (x == X_START && y == Y_START) {
		return 0; //此刻位于起点
	}
	return (x == 0 || x == 11 || y == 0 || y == 11); //此时位于终点
}
