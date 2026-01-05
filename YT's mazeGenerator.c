#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 12

void mazeGenerator(char maze[SIZE][SIZE],int x,int y);
void printMaze(char maze[SIZE][SIZE]);
int validMove(int x,int y,char maze[SIZE][SIZE]);

int main(void)
{
    char maze[12][12] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
    };

    srand(time(NULL));
    int startX,startY,endX = -1,endY = -1;
    startX = rand()%12;
    do
    {
        startY = rand()%12;
    }while((startX != 0 && startX != 11) && (startY != 0 && startY != 11));     

    endX = rand()%12;
    do  
    {
        endY = rand()%12;
    }while((endX != 0 && endX != 11) && (endY != 0 && endY != 11) && !(endX == startX || endY == startY));

    mazeGenerator(maze,startX,startY);
    maze[startX][startY] = 'X';
    maze[endX][endY] = 'O';
    printMaze(maze);
    printf("起点是(%d,%d)",startX,startY);
    printf("终点是(%d,%d)",endX,endY);
    return 0;
}

void mazeGenerator(char maze[SIZE][SIZE],int x,int y)
{
    int moveX[4] = {0,1,-1,0}; //决定X方向的移动方向
    int moveY[4] = {1,0,0,-1}; //决定Y方向的移动方向

    srand(time(NULL));

    for(int i = 0;i<4;i++){
        int newX = x + moveX[i]*2; //一次性走两格
        int newY = y + moveY[i]*2;

        if(validMove(newX,newY,maze)){
            maze[newX][newY] = '.';
            maze[x + moveX[i]][y + moveY[i]] = '.';
            mazeGenerator(maze,newX,newY);
        }
    }

}

void printMaze(char maze[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}

int validMove(int x,int y,char maze[SIZE][SIZE])
{
    return (x >= 0 && x < 11 && y >= 0 && y < 11 && maze[x][y] == '#'); //在迷宫的边界内且对象是墙
}
