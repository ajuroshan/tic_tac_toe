#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void printgrid();
void takeuserinput();
void updategrid();
void computer();
void wincheck();

char grid[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},

};

int useposrow, useposcol;
int gameover = 0;

void main()
{
    // Tic Tac Toe
    printf("Hi Welcome to Tic Tac Toe!\n");
    printf("\n");
    // printgrid();
    while (gameover != 1)
    {
        printf("Your Turn:\n");

        takeuserinput();
        updategrid();
        printgrid();
        wincheck();
        printf("\n");
        printf("Computers Turn:\n");
        sleep(1);
        computer();
        printgrid();
        sleep(1);
        printf("\n");
    }
    printf("Thanks for Playing!");
}

void takeuserinput()
{
    scanf("%d %d", &useposrow, &useposcol);
    printf("\n");
}

void updategrid()
{
    grid[useposrow - 1][useposcol - 1] = 'X';
}

void printgrid()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%c\t", grid[row][col]);
        }
        printf("\n");
    }
}

void computer()
{
    srand(time(NULL));
    int row, col, done = 1;
    while (done)
    {
        row = rand() % 3;
        col = rand() % 3;
        if (grid[row][col] != 'X' && grid[row][col] != '0')
        {
            grid[row][col] = '0';
            done = 0;
        }
    }
}

void wincheck()
{
    // printf("%c %c %c \n", grid[0][0], grid[0][1], grid[0][2]);
    if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X' ||
        grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X' ||
        grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X' ||

        grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X' ||
        grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X' ||
        grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X' ||

        grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
    {
        printf("You Win\n");
        gameover = 1;
    }
    else if (grid[0][0] == '0' && grid[0][1] == '0' && grid[0][2] == '0' ||
             grid[1][0] == '0' && grid[1][1] == '0' && grid[1][2] == '0' ||
             grid[2][0] == '0' && grid[2][1] == '0' && grid[2][2] == '0' ||

             grid[0][0] == '0' && grid[1][0] == '0' && grid[2][0] == '0' ||
             grid[0][1] == '0' && grid[1][1] == '0' && grid[2][1] == '0' ||
             grid[0][2] == '0' && grid[1][2] == '0' && grid[2][2] == '0' ||

             grid[0][0] == '0' && grid[1][1] == '0' && grid[2][2] == '0')
    {
        printf("Computer Win\n");
        gameover = 1;
    }
}
