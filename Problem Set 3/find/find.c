/**
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
const int MAX = 65536;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);             // needle (element that we seek)

    // fill haystack
    int size;
    int haystack[MAX];                      // a stack of hay
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%i] = ", size);
        int straw = get_int();              // we create our "straw"
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;             // add "haystack, straw ':)
    }
    printf("\n");

    // sort the haystack
    sort(&haystack[0], size);
       
    // try to find needle in haystack
    if (search(needle, haystack, size))             // pass the needle -> element that we seek, haystack -> array, size
    {
        printf("\nFound needle in haystack!\n\n");  // if there is an element in the array, saying that "it is"
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n"); // if the element is not present, saying that "no"
        return 1;
    }
}
