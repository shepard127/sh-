#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


#define SIZE 1000000        // size hash-table

typedef struct node         // structure node linked list
{
    char word[LENGTH+1];
    struct node* next;
}
node;

node* hashtable[SIZE] = {NULL};     // create hash-table

int hash (const char* word)         // function create hash
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

int dictionarySize = 0;     // here we will store dictionary size

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r"); // open dictionary
    
    if (file == NULL)
        return false;
    
    char word[LENGTH+1];
    
    while (fscanf(file, "%s\n", word)!= EOF)    // run a dictionary, reading the word, and so long as the file does not end
    {
        node* newWord = malloc(sizeof(node));   
        
        strcpy(newWord->word, word);            
        
        int index = hash(word);                 
        
        if (hashtable[index] == NULL)           
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        else                                    // if the word is in the dictionary
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }
        
        dictionarySize++;                       // increase size
    }
    
    fclose(file);                               // close file   
    
    return true;                
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char buff[LENGTH + 1];                      // create temporary variable for store word in low register
    int lenght = strlen(word);
    for(int i = 0; i < lenght; i++)
        buff[i] = tolower(word[i]);
    buff[lenght] = '\0';
    
    int index = hash(buff);                     // or obtain the hash word, or its index into the hash table
    
    if (hashtable[index] == NULL)               // check that we got
    {
        return false;
    }
    
    node* marker = hashtable[index];            // create node (our words), and immediately put in hash-table
    
    while (marker != NULL)                      // if current index(hash) not NULL, sort out the words and compare them
    {
        if (strcmp(buff, marker->word) == 0)
        {
            return true;
        }
        marker = marker->next;
    }

    return false;                               // if none found return false
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (dictionarySize > 0)                         // if dictionary not empty, return lenght dictionary
        return dictionarySize;
    else
        return 0;                                   // else return 0
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < SIZE; i = i + 0)
    {
        if (hashtable[i] == NULL)                   // if the current index (hash table) there's nothing going on
            i++;
        else                                        // else, iterate through nodes and clean for a memory
        {
            while(hashtable[i] != NULL)
            {
                node* marker = hashtable[i];
                hashtable[i] = marker->next;
                free(marker);
            }
            i++;                                    // step to next hash index
        }
    }
    return true;
}
