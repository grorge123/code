#include <stdio.h>
#include<iostream>
using namespace std;
#include <string.h>
int MazeSize = 7, CommandLen = 5+1, NumCommands = 10;
void RobotMove(int *x,int *y,const char maze[MazeSize][MazeSize],const char commands[NumCommands][CommandLen]){
    int t=0;
    while(commands[t]!="END"){
        if(commands[t]=="UP"&&maze[*x][*y+1]=='.')*y+=1;
        if(commands[t]=="DOWM"&&maze[*x][*y-1]=='.')*y-=1;
        if(commands[t]=="RIGHT"&&maze[*x+1][*y]=='.')*x+=1;
        if(commands[t]=="LEFT"&&maze[*x-1][*y]=='.')*x-=1;
    t++;
    }

}

// ------------------------------------------
int main()
{
    char maze[MazeSize][MazeSize]= {};
    for (int i=MazeSize-1; i>=0; i-=1)
    {
        for (int j=0; j<MazeSize; j+=1)
        {
            scanf(" %c", &maze[i][j]);
        }
    }
    char commands[NumCommands][CommandLen]= {};
    int t=0;
    scanf("%s",commands[t]);
    while(commands[t]!="END"){
        t++;
        scanf("%s",commands[t]);
    }

    int x=0, y=0;
    scanf("%d%d", &y, &x);
    RobotMove(&x, &y, maze, commands);
    printf("Now the robot is at (%d, %d).\n", y, x);
    return 0;
}
