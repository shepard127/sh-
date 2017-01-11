#include <iostream>
#include <string.h>

using namespace std;

void upperCase(char* p_str, int lenght);
void countInputLeter(char* p_str, int lenght);

int main()
{
    char str[100] = {0};
    cout << "Enter string please: ";
    gets(str);

    upperCase(&str[0], strlen(str));
    countInputLeter(&str[0], strlen(str));

    return 0;
}
void upperCase(char* p_str, int lenght)
{
    for(int i = 0; i < lenght; i++)
        if(isalpha(*(p_str + i)))
           *(p_str + i) = toupper(*(p_str + i));
}

void countInputLeter(char* p_str, int lenght)
{
    char compare;
    char print = ' ';
    int count = 0;

    for(int i = 0; i < lenght; i++)
    {
        compare = *(p_str + i);
        if(isalpha(compare))
        {
            for(int j = 0; j < lenght; j++)
                if(compare == *(p_str + j))
                {
                    print = *(p_str + j);
                    count++;
                    *(p_str + j) = ' ';
                }

            cout << "\n" << print << "\t" << count;
        }
        count = 0;
    }
    cout << endl;

}





