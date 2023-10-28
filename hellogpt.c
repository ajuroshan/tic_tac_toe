#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Symbol
{
    EMPTY,
    USER,
    COMPUTER
};

int grid[3][3];

// Function prototypes
void initializeGrid();
void printGrid();
int takeUserInput();
int updateGrid(int row, int col, enum Symbol symbol);
int computerMove();
int checkWin(enum Symbol symbol);
int isGridFull();

void initializeGrid()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            grid[row][col] = EMPTY;
        }
    }
}

void printGrid()
{
    system("clear"); // Use "cls" for Windows
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row][col] == EMPTY)
            {
                printf(" - ");
            }
            else if (grid[row][col] == USER)
            {
                printf(" X ");
            }
            else
            {
                printf(" O ");
            }
            if (col < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (row < 2)
        {
            printf("-----------\n");
        }
    }
}

int takeUserInput()
{
    int row, col;
    printf("Enter your move (row and column, e.g., 1 2): ");
    scanf("%d %d", &row, &col);
    row--; // Adjust for 0-based indexing
    col--;

    if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != EMPTY)
    {
        printf("Invalid move. Try again.\n");
        return 1; // Continue the game
    }

    return updateGrid(row, col, USER);
}

int updateGrid(int row, int col, enum Symbol symbol)
{
    grid[row][col] = symbol;
    return 0;
}

int computerMove()
{
    int row, col;
    while (1)
    {
        row = rand() % 3;
        col = rand() % 3;
        if (grid[row][col] == EMPTY)
        {
            updateGrid(row, col, COMPUTER);
            return 1; // Valid move
        }
    }
}

int checkWin(enum Symbol symbol)
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
        {
            return 1; // Row win
        }
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
        {
            return 1; // Column win
        }
    }

    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
    {
        return 1; // Diagonal win (top-left to bottom-right)
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
    {
        return 1; // Diagonal win (top-right to bottom-left)
    }

    return 0; // No win
}

int isGridFull()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row][col] == EMPTY)
            {
                return 0; // Grid is not full
            }
        }
    }
    return 1; // Grid is full
}

int main()
{
    srand(time(NULL));
    initializeGrid();
    printGrid();

    while (1)
    {
        if (takeUserInput() == 0)
            printGrid();

        if (checkWin(USER))
        {
            printf("You Win!\n");
            break;
        }
        else if (isGridFull())
        {
            printf("It's a tie!\n");
            break;
        }

        if (computerMove() == 0)
            break;
        printGrid();

        if (checkWin(COMPUTER))
        {
            printf("Computer Wins!\n");
            break;
        }
        else if (isGridFull())
        {
            printf("It's a tie!\n");
            break;
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}
