/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int l_needle, int l_haystack[], int size)
{  
    if(l_haystack[size/2] == l_needle)
        return true;                    // true 
    if(size < 2)
        return false;                   // false
    
    if(l_haystack[size/2] > l_needle)
        return search(l_needle, l_haystack, size/2);
        
    if(l_haystack[size/2] < l_needle)
        return search(l_needle, &l_haystack[size/2 + 1], size/2 - 1);
        
    return false;       // to check the plug(clang swears by the function-default returns nothing)
}

/**
 * Sorts array of n values.
 */
void sort(int* p_haystack, int size)
{
    int buff = 0;                       // variables that will help us in sorting  
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            /*if(values[j] > values[j+1]) // If the current element is larger following - changing elements in places
            {
                buff = values[j];
                values[j] = values[j+1];
                values[j+1] = buff;
            }
            */
            if(*(p_haystack + j) > *(p_haystack + (j+1)))
            {
                buff = *(p_haystack + j);
                *(p_haystack + j) = *(p_haystack + (j+1));
                *(p_haystack + (j+1)) = buff;
            }
        }
    }
    return;
}
