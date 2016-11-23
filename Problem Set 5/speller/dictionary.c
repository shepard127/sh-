#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


#define SIZE 1000000        // размер хеш-таблицы

typedef struct node         // структура нод связанного списка
{
    char word[LENGTH+1];
    struct node* next;
}
node;

node* hashtable[SIZE] = {NULL};     // создание хеш-таблицы

int hash (const char* word)         // функция создания хеша
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if(isalpha(word[i]))        
            n = word [i] - 'a' + 1;
        
        else                         
            n = 27;
            
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;    
}

int dictionarySize = 0;     // здесь мы будем хранить рамер словаря

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r"); // открываем словарь
    
    if (file == NULL)
        return false;
    
    char word[LENGTH+1];
    
    while (fscanf(file, "%s\n", word)!= EOF)    // бежим по словарю, считываем по слову, и так пока файл не закончится
    {
        node* newWord = malloc(sizeof(node));   
        
        strcpy(newWord->word, word);            
        
        int index = hash(word);                 
        
        if (hashtable[index] == NULL)           
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        else                                    // если лежит (в словаре)
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }
        
        dictionarySize++;                       // увеличили размер
    }
    
    fclose(file);                               // закрыли файл   
    
    return true;                
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char buff[LENGTH + 1];                      // создаем временную переменную для храннения слова в нижнем регистре
    int lenght = strlen(word);
    for(int i = 0; i < lenght; i++)
        buff[i] = tolower(word[i]);
    buff[lenght] = '\0';
    
    int index = hash(buff);                     // получаем либо хеш слова, либо его индекс в хеш-таблице
    
    if (hashtable[index] == NULL)               // проверяем что мы получили
    {
        return false;
    }
    
    node* marker = hashtable[index];            // создаем ноду наше слово, и сходу пихаем ее в хеш-таблицу
    
    while (marker != NULL)                      // если по данному индексу хеш не пустой, перебираем слова и сравниваем их
    {
        if (strcmp(buff, marker->word) == 0)
        {
            return true;
        }
        marker = marker->next;
    }

    return false;                               // если мы его так и не нашли вертаем false
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (dictionarySize > 0)                         // если словарь не пустой, вертаем длинну словаря
        return dictionarySize;
    else
        return 0;                                   // иначе возвращаем его длинну(ноль вертаем так-как он пуст)
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < SIZE; i = i + 0)
    {
        if (hashtable[i] == NULL)                   // если хеш-таблица по-индексу пустая идем дальше
            i++;
        else                                        // иначе, перебираем узлы и чистим за собой память
        {
            while(hashtable[i] != NULL)
            {
                node* marker = hashtable[i];
                hashtable[i] = marker->next;
                free(marker);
            }
            i++;                                    // как только натыкаемся на пустой хеш, переходим на следующий хеш
        }
    }
    return true;                        // вертаем true в случае успеха
}
