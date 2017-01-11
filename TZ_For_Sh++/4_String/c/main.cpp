#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100] = {0};
    gets(str);

    for(int i = 0; i < strlen(str); i++)
        if((isalpha(str[i])) && (str[i] >= 97))
            str[i] -= 32;

    puts(str);
    return 0;
}
