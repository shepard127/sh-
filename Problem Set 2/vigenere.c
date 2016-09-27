#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool test_key(int p_argc, string p_argv);                                                                                           /* функция принимает argc и argv, затем проверяет их на коректность ввода */
void alphabet_arr(char* alphabet, int size_arr, char l_step, bool lit_alphabet);
void primary_function(string l_plain_str, string crypto_str);																		/* самая главная функция программы, в ней весь сок */
void mixing_arr(int* p_mixing, int size_mixing, string p_crypto_str, int size_crypto_str, char* p_alphabet_l, char* p_alphabet_b);	/* считает, на сколько нам нужно смещать буквы текста */
int defin_reg_alphabet(char pp_crypto_str);																							/* определяет регистр алфавита */

int main(int argc, string argv[])
{
    bool test = false;
    string str = argv[1];                               // готовим наш параметр к передаче на проверку
    
    test = test_key(argc, str);                         // передаем в функцию проверки кол-во параметров и строку второго параметра
    
    if (test != false)                                  // если нет ошибок ввода
    {
        //основной цикл программы
        printf("plaintext: ");
        string plain_str = GetString();
        //printf("\nplaintext%s", plain_str);           //debug (выводит текст который пользователь ввел)
        primary_function(plain_str, str);               // главная функция
        
    }
    else 
    {
        return 1;
    }
    return 0;
}

bool test_key(int p_argc, string p_argv)
{
    if(p_argc <= 1 || p_argc > 2)
    {
        printf("Usage: ./vigenere k");
        return false;
    }
    else
    {
        for(int i = 0; i < strlen(p_argv); i++)
        {
            if(p_argv[i] >= '0' && p_argv[i] <= '9')    // Если нашли число
            {
                printf("Usage: ./vigenere k");
                return false;                   
            }
        }
    } 
    return true;    									// Ошибок нет
}

void alphabet_arr(char* alphabet, int size_arr, char l_step, bool lit_alphabet)
{
	/* знаю, цыфры использовать нельзя, но я уже и так задержал сроки. Нет времени делать рефакторинг */
	for (int i = 0; i < size_arr; i++)
	{
		*(alphabet + i) = l_step;						    // записать букву в массив

		if (i == 25 && lit_alphabet)						    // если заполнили наполовину
		{
			l_step = 97;	/* ASCII (DEC) */				    // сбрасываем шаг
		}
		else if (i == 25 && lit_alphabet != true)
		{
			l_step = 65;	/* ASCII (DEC) */				    // сбрасываем шаг
		}
		else
			l_step++;							    // выбрать следующую букву
	}
}
void mixing_arr(int* p_mixing, int size_mixing, string p_crypto_str, int size_crypto_str, char* p_alphabet_l, char* p_alphabet_b)
{
	int branch = 0;
	const int LENGHT_ALPHABET = 26;

	for (int i = 0; i < size_crypto_str; i++)
	{
		branch = defin_reg_alphabet(p_crypto_str[i]);																		

		switch (branch)
		{
			case 1:																											
			{
				for (int j = 0; j < LENGHT_ALPHABET; j++)
				{
					if(p_crypto_str[i] == (*p_alphabet_l + j))
						*(p_mixing + i) = j;
				}
				break;
			}
			case 2:																											
			{
				for (int j = 0; j < LENGHT_ALPHABET; j++)
				{
					if(p_crypto_str[i] == (*p_alphabet_b + j))
						*(p_mixing + i) = j;
				}
				break;
			}
			default:																										
			{
				*(p_mixing + i) = 0;					
				break;
			}
		}
	}
}

int defin_reg_alphabet(char pp_crypto_str)
{

	if (pp_crypto_str >= 'a' && pp_crypto_str <= 'z')
	{
		return 1;
	}
	else if (pp_crypto_str >= 'A' && pp_crypto_str <= 'Z')
	{
		return 2;
	}
	else 
		return 0;
}

void primary_function(string plain_str, string crypto_str)
{
	char alphabet_l[52], alphabet_b[52];
	char step = 97;																		// шагаем с 97 ASCII
	bool lit_or_big = true;																// TRUE нужен для нижнего регистра
	alphabet_arr(&alphabet_l[0], sizeof(alphabet_l), step, lit_or_big);				// заполняем массив, маленькими буквами

	lit_or_big = false;																	// FALSE нужен для верхнего регистра
	step = 65;																			// шагаем с 97 ASCII
	alphabet_arr(&alphabet_b[0], sizeof(alphabet_b), step, lit_or_big);				// заполняем массив, большими буквами
	
	int mixing[strlen(crypto_str)];														// здесь мы будем хранить значения смещений(насколько смещать каждую букву)
	
	mixing_arr(&mixing[0], sizeof(mixing), crypto_str, strlen(crypto_str), &alphabet_l[0], &alphabet_b[0]);
	
	char crypto_result[strlen(plain_str)];								// здесь будем хранить зашифрованый текст
	const int LENGHT_ALPHABET = 26;									
	short int shift = 0;										// счетчик для сброса Mixing[]
	
	for (int i = 0; i < strlen(plain_str); i++)
	{
		short int branch = defin_reg_alphabet(plain_str[i]);					// проверяем что у нас за буква (Верхний рег., нижний рег., или вообще не буква)

		switch (branch)												
		{
			case 1:
				{
					for (int k = 0; k < LENGHT_ALPHABET; k++)			// ищем нашу букву среди букв нижнего регистра
					{
						if (plain_str[i] == alphabet_l[k])			// если нашли
						{
							if (shift == strlen(crypto_str))		// если мы дошли до конца ключа
								shift = 0;				// сброс на начало ключа
				
							int temp = k + mixing[shift];			// считаем, какой будет индекс по алфавиту после смещения
							crypto_result[i] = alphabet_l[temp];		// заполняем crypto_result[i], нашими зашифроваными буквами
							
							shift++;					// ползём дальше, по ключу шифрования
															
						}
					}
					break;
				}
			case 2:
				{
					for (int k = 0; k < LENGHT_ALPHABET; k++)			// ищем нашу букву среди букв верхнего регистра
					{
						if (plain_str[i] == alphabet_b[k])			// если нашли
						{
							if (shift == strlen(crypto_str))		// если мы дошли до конца ключа
								shift = 0;				// сброс на начало ключа

							int temp = k + mixing[shift];			// считаем, какой будет индекс по алфавиту после смещения
							crypto_result[i] = alphabet_b[temp];		// заполняем crypto_result[i], нашими зашифроваными буквами

							shift++;					// ползём дальше, по ключу шифрования
						}
					}
					  break;
				}
			default:
				{
					crypto_result[i] = plain_str[i];				// сюда заходи только когда текущий символ не буква
					break;
				}	
		}
	}
	/*		RESULT =)   	*/
	printf("ciphertext:");
	for (int i = 0; i < strlen(plain_str); i++)							// выводим зашифрованый текст
	{
		printf("%c", crypto_result[i]);
	}
	printf("\n");
}
