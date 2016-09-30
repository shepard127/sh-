#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string name = GetString();
    
    const int FIRST_LITTLE_LETTER = 65;
    const int LAST_LITTLE_LETTER  = 90;
    const int FIRST_BIG_LETTER    = 97;
    const int LAST_BIG_LETTER     =122;
    
    bool ka = true;
    
    for (int i = 0; i < strlen(name); i++)
    {
        if((name [i] >= FIRST_LITTLE_LETTER && name [i] <= LAST_LITTLE_LETTER) || (name[i] >= FIRST_BIG_LETTER && name[i] <= LAST_BIG_LETTER))                 // сравниваем по ASCII
        {
            if(ka == true)
            {
                printf("%c", toupper(name[i]));
            }
            if((name[i+1] >= FIRST_LITTLE_LETTER && name [i+1] <= LAST_LITTLE_LETTER) || (name[i+1] >= FIRST_BIG_LETTER && name[i+1] <= LAST_BIG_LETTER))      // сравниваем по ASCII
            ka = false;
            else
            ka = true;
        }
    }
    printf("\n");
    return 0;
}
