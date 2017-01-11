#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100];
    gets(str);

    int  countBuff = 0, lenghtWord = 0, indexBuff = 0;
    char buff[10], word[10] = {NULL};
    bool startWord = false;
    bool endWord = false;

    for(int i = 0; i < strlen(str); i++)
    {
        if((isalpha(str[i]) && !(startWord)) || (isalpha(str[i])))
        {
            startWord = true;
            buff[indexBuff] = str[i];
            indexBuff++;
            endWord = false;
        }
        else if(! isalpha(str[i]) && startWord)
        {
            startWord = false;
            buff[indexBuff] = NULL;
            endWord = true;
            indexBuff = 0;
        }

        if(i == (strlen(str)-1))
            endWord = true;

        if((strlen(buff) > strlen(word)) && endWord)
        {
            strcpy(word, buff);
            endWord = false;
            indexBuff = 0;
        }
    }
    cout << "\n";
    puts(word);

    return 0;
}
