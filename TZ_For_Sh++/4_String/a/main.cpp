#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    gets(str);

    int  countWord = 0;
    bool startWord = false;

    for(int i = 0; i < strlen(str); i++)
    {
        if(isalpha(str[i]) && !startWord)
            startWord = true;
        else if(! isalpha(str[i]) && !startWord)
        {
            countWord++;
            startWord = false;
        }

        if((i == (strlen(str)) - 1) && startWord)
            countWord++;
    }
    cout << "\nAmount words: " << countWord <<endl;

    return 0;
}

