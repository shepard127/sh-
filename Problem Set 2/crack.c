#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");                // проверяем колличество введенных параметров
        return 1;
    }


    char *hash = argv[1];                               // создаем указатель на строку hash

    char salt[3] = {hash[0], hash[1], 0};               // выгребаем два первых элемента в соль

    char letter1 = 'A';                                  
    char letter2 = 'A';
    char letter3 = 'A';
    char letter4 = 'A';

    char *result;                                                       // указатель на результат 

    while (letter1 != 'z'+1)                                            // шагаем по ASCII пока не выйдем за маленькую букву 'z'
    {
        char keyOne[2] = {letter1, 0};                                  // ключ состоящий из одного символа

        result = crypt(&keyOne[0], salt);                               // функция crypt возвращает нам HASH, а наш result будет указывать на начало HASH'a

        if (strcmp(result, hash) == 0)                                  // сравниваем HASH(сгенерированый функцей crypt), с HASH который мы ввели в качестве параметра 
        {
            printf ("%s\n", keyOne);                                    // если совпали, выводим слово на котором совпало
            return 0;
        }

        while (letter2 != 'z'+1)
        {
            char keyTwo[3] = {letter1, letter2, 0};                             // тоже самое делаем, только уже с двумя буквами

            result = crypt(&keyTwo[0], salt);

            if (strcmp(result, hash) == 0)
            {
                printf ("%s\n", keyTwo);
                return 0;
            }

            while (letter3 != 'z'+1)
            {
                char keyThree[4] = {letter1, letter2, letter3, 0};              // тоже самое делаем, только уже с тремя буквами

                result = crypt(&keyThree[0], salt);

                if (strcmp(result, hash) == 0)
                {
                    printf ("%s\n", keyThree);
                    return 0;
                }

                while (letter4 != 'z'+1)
                {
                    char keyFour[5] = {letter1, letter2, letter3, letter4, 0};  // тоже самое делаем, только уже с тремя буквами

                    result = crypt(&keyFour[0], salt);

                    if (strcmp(result, hash) == 0)
                    {
                        printf ("%s\n", keyFour);
                        return 0;
                    }

                    letter4++;
                    if (letter4 == 'Z'+1)
                        letter4 = 'a';
                }
                letter3++;
                if (letter3 == 'Z'+1)
                    letter3 = 'a';

                letter4 = 'A';
            }
            letter2++;
            if (letter2 == 'Z'+1)
                letter2 = 'a';
            letter3 = 'A';
        }
        letter1++;                                                              // бежим дальше по ASCII коду
        if (letter1 == 'Z'+1)                                                   // если дошли до последней буквы большого алфавита, перебрасываем на маленький
            letter1 = 'a';
        letter2 = 'A';                                                          // сбрасываем следующую букву на начало большого алфавита в ASCII
    }

    return 1;
}
