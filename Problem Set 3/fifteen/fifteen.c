/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                 // for usleep()

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
char board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);       // ready
void init(void);        
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)             // check that the user entered there
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();                                           

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing) 
           for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win    
        if (won())
        {
            printf("You WIN!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    //system("clear");
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int col = 0, row = 0, temp = d*d - 1;
    while(row < d)
    {
        while(col < d)
        {
            board[row][col] = temp;
            temp--;
            col++;
        }
        col = 0;
        row++;
    }
    
    //executed at the very end
    if(row == d)
    {
        if((board[0][0] % 2) != 0)                                  // If our matrix begins at an odd item - the 1 and 2 change places
        {
            int replace = d - 1;
            int buff = board[replace][replace - 2];
            board[replace][replace - 2] = board[replace][replace - 1];
            board[replace][replace - 1] = buff;             
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int col = 0, row = 0;
    while(row < d)
    {
        while(col < d)
        {
            if(board[row][col] == 0)
            {
                printf("%c", ' ');
                printf("%c", '_');
                if (col < d - 1)
                {
                    printf("|");
                }
            }
            else if(board[row][col] < 10)
            {
              printf(" %d", board[row][col]);
              if(col < d - 1)
              {
                  printf("|");
              }
            }
            else
            {
                printf("%i", board[row][col]);
                if (col < d - 1)
                {
                    printf("|");

                }

            }
            col++;
        }
        printf("\n");
        col = 0;
        row++;
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    /* 1 - determine the current position of the tile */
    /* 2 - if the range of cells from the first tile, is zero - then change the tile with zero places */
    
    int row = 0, col =0;
    while(row < d)
    {
        while(col < d)
        {
            if(board[row][col] == tile)
            {
                if(board[row][col+1] == 0 && col+1 < d)
                {
                    int temp = 0;
                    temp = board[row][col];
                    board[row][col] = board[row][col+1];
                    board[row][col+1] = temp;
                    return true;
                }
                else if(board[row][col-1] == 0 && col-1 >= 0)
                {
                    int temp = 0;
                    temp = board[row][col];
                    board[row][col] = board[row][col-1];
                    board[row][col-1] = temp;
                    return true;
                }
                else if(board[row+1][col] == 0 && row+1 < d)
                {
                    int temp = 0;
                    temp = board[row][col];
                    board[row][col] = board[row+1][col];
                    board[row+1][col] = temp;
                    return true;
                }
                else if(board[row-1][col] == 0 && row-1 >= 0)
                {
                    int temp = 0;
                    temp = board[row][col];
                    board[row][col] = board[row-1][col];
                    board[row-1][col] = temp;
                    return true;
                }
                return false;
            }
            col++;
        }
        col = 0;
        row++;
    }
    
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int row = 0, col = 0, testwon = 1;
    while (row < d)
    {
        while(col < d)
        {
            if(board[row][col] == testwon)
            {
                if(board[d - 1][d - 1] == 0 && testwon == d*d-1)
                {
                    return true;
                }
                testwon++;   
            }
            col++;
        }
        col = 0;
        row++;
    }
    
    return false;
}
