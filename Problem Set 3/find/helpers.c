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
    // TODO: implement a searching algorithm
    
    if(l_haystack[size/2] == l_needle)
        return true;                   // true 
    if(size < 2)
        return false;                   // false
    
    if(l_haystack[size/2] > l_needle)
        return search(l_needle, l_haystack, size/2);
        
    if(l_haystack[size/2] < l_needle)
        return search(l_needle, &l_haystack[size/2 + 1], size/2 - 1);
        
    return false;       // заглушка для проверки(clang ругается когда функция по-default ничего возвращает)
}

/**
 * Sorts array of n values.
 */
void sort(int* p_haystack, int size)
{
    // TODO: implement an O(n^2) sorting algorithm
    int buff = 0;                       // переменая которая будет поможет нам в сортировке  
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            /*if(values[j] > values[j+1]) // если текущий элемент больше следующиего - меняем элементы местами
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
