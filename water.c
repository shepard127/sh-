//программа работет, осталось оптимизировать ее по Edx_IDE, и залить на GitHub
// и не забудь перевести комментарии на ангийский, и програнать прогу, автотестами на Edx_IDE


#include <stdio.h>
int main ()
{
    int time = 0;                                           //создаем переменную
    printf("How any minute you lave in shower-bath?\n");    //спаришивем сколько минут
    scanf("%d",  &time);                                    //считываем ответ
    printf("\n");

    if (time > 0)                                           //проверям значение
    {
        printf("Cool!\n");                                  //debug
        time = (time*6)*2;                                  //считаем
        printf("You spend %d %s", time,"bottle water!\n");  //выводим
    }
    else if (time <= 0)                                       //если 0 или < 0
        printf("Please reboot program, and enter minute > 0");//просим перезагрузить программу, и ввести данные > 0

    return 0;
}
