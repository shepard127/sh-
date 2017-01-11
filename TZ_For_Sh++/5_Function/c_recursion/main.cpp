#include <stdio.h>
#include <windows.h>    // для работы system("cls") -> очистка экрана
#include <clocale>      // для работы setlocale -> подтягиваем кирилицу
using namespace std;

void search(char l_str[]);

int main()
{
    setlocale(LC_ALL, "");
    char str[5];
    printf("Введите число которое будем угадывать: ");
    gets(str);
    printf("%s\n", str);
    system("cls");
    search(str);
    printf("\nВы выиграли!");
    return 0;
}

void search(char l_str[])
{
    short int bull = 0, cow = 0;
    char buffer[5];
    printf("\nУгадай число: ");
    gets(buffer);
    system("cls");

    for(int i = 0; i < strlen(l_str); i++)
    {
        for(int j = 0; j < strlen(l_str); j++)
        {
            if(buffer[i] == l_str[j])
            {
                if(i == j)
                    bull++;
                else
                    cow++;
            }
        }
    }
    printf("\n Быков: %d", bull);
    printf("\n Коров: %d", cow);
    if (bull != 4)
        search(l_str);
}
