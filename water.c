#include <stdio.h>
#include <cs50.h>
int main ()
{
    printf("minutes: ");                                
    int time = get_int();                                   
    printf("\n");

    if (time > 0)                                          
    {
        time = (time*6)*2;                                  
        printf("bottles: %d", time);  
    }

    return 0;
}
