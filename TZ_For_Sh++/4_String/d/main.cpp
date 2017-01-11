#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100] = {0};
    int count = 0;
    char print = ' ';
    char compare;

    cout << "Enter string please: ";
    gets(str);

    for(int i = 0; i < strlen(str);i++)
        if(isalpha(str[i]))
           str[i] = toupper(str[i]);

    for(int i = 0; i < strlen(str); i++)
    {
        compare = str[i];
        if(isalpha(compare))
        {
            for(int j = 0; j < strlen(str); j++)
                if(compare == str[j])
                {
                    print = str[j];
                    count++;
                    str[j] = ' ';
                }

            cout << "\n" << print << "\t" << count;
        }
        count = 0;
    }
    cout << endl;
    return 0;
}

