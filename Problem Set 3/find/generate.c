/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");    // deduce if the number of arguments, not 2 and not 3
        return 1;
    }

    int n = atoi(argv[1]);                      // convert the element to an int

    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));          // the user has entered the 3rd argument, use it to initialize drand48 ()
    }
    else
    {
        srand48((long) time(NULL));             // otherwise take a random number
    }

    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));  // returns us to the value of (double type), we multiply by 65536, and print as an int
    }

    // success
    return 0;
}
