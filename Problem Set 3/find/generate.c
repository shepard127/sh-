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
    // TODO: comment me
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");    // выводим если колличество аргументов, не 2 и не 3
        return 1;
    }

    // TODO: comment me
    int n = atoi(argv[1]);                      // конвертируем элемент в int

    // TODO: comment me
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));          // пользователь ввел 3-й аргумент, используем его для инициализации drand48()
    }
    else
    {
        srand48((long) time(NULL));             // иначе берем рандомное число
    }

    // TODO: comment me
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));  // возвращает нам значение (типа double), мы его множим на 65536, и выводим как int
    }

    // success
    return 0;
}
