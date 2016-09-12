//вроде все есть, добавь коменты на инглиш, оптимизируй под Edx_IDE, и залей на GitHub
#include <stdio.h>
#include <cs50.h>
void func_R1(int i_probel, int s_stroka);

int main ()
{
    int height = -1;
    printf("Enter please height pyramid: ");
    //scanf("%d", &height);
     
     height = get_int();
     
     while (height < 0 || height > 23)
    {
        printf("Retry: ");
        height = get_int();
    }

    if ((height > 0) && (height <= 23))
    {
      //  printf("Cool \n");

        int i; //счетчик
        for (i = 1; i <= height; i++)
        {
            int probel = 0, reshotka = 0;
            probel = height - i; //считаем кол-во пробелов
            reshotka = height - probel;

            int j; //счетчик
            for(j = 0; j < probel; j++)
            {
                printf("%c", ' ');
            }

            int k; //счетчик
            for(k = 0; k < reshotka; k++)
            {
                printf("%c", '#');
            }
            printf("  ");

            for(k = 0; k < reshotka; k++)
            {
                printf("%c", '#');
            }
            /*for(j = 0; j < probel; j++)
            {
                printf("%c", ' ');
            }*/
            printf("\n");
        }
    }


    return 0;
}
