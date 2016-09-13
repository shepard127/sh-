#include <stdio.h>
#include <cs50.h>

int main ()
{
    int height = 0;
    printf("Enter please height pyramid: ");
     
     height = get_int();                    // Read the number that the user enters
     
     while (height < 0 || height > 23)
    {
        printf("Retry: ");                  // If the numbers from the range, please enter again
        height = get_int();                 // Read the number that the user enters
    }
    
    int i; //counter
    for (i = 1; i <= height; i++)
    {
        int probel = 0, reshotka = 0;
        probel = height - i;            // We count the number of spaces
        reshotka = height - probel;     // We expect the number of lattices

        int j; //counter
        for(j = 0; j < probel; j++)
        {
            printf("%c", ' ');          // We print spaces for the first pyramid
        }

        int k; //counter
        for(k = 0; k < reshotka; k++)
        {
            printf("%c", '#');          // We print lattices for the first pyramid
        }
        printf("  ");

        for(k = 0; k < reshotka; k++)
        {
            printf("%c", '#');          // We print gaps for the second pyramid
        }
        printf("\n");
    }
    return 0;
}
