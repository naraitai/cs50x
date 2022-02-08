/*---------------------------------
Task 2 of 2

Brief
- Implement a program the spell-checks a file using a hash table
- Implement load
- Implement hash
- Implement size
- Implement check
- Implement unload
- Implement as efficiently as possible with a hash table

Expected output
    
    ./speller texts/lalaland.txt
    MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
    
Distribution code
- Shown as follows 
    >>>>>Distribution code start<<<<<
    >>>>>>Distribution code end<<<<<<
- dictionaries (dir)
- keys (dir)
- text (dir)
- dictionary.h
- Makefile
- speller.c

Key concept:
- Data structures
-----------------------------------*/

// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

/*>>>>>Distribution code start<<<<<*/
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];
/*>>>>>>Distribution code end<<<<<<*/

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Lookup with hash
    unsigned int hash_value = hash(word);
    node *trav = table[hash_value];
    
    // Loop linked list for word
    while (trav != NULL)
    {
        if (strcasecmp(word, trav->word) == 0)
        {
            return true;
        }

        trav = trav->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Simple case-insensitive hash
    unsigned int hash = 0;

    for (int i = 0, n = strlen(word); i < n - 1; i++)
    {
        hash += tolower(word[i]);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
int count = 0;
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    
    // Loop each word adding it to hash table
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF) //feof(dict) == 0)
    {
        count++;

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);

        unsigned int hash_value = hash(n->word);

        n->next = table[hash_value];
        table[hash_value] = n;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return global count variable as size
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loop through array freeing linked list elements
    for (int i = 0; i <= N; i++)
    {
        node *trav = table[i];

        while (trav != NULL)
        {
            node *tmp = trav;
            trav = trav->next;
            free(tmp);
        }
        
        if (trav == NULL && i == N)
        {
            return true;
        }
    }
    
    return false;
}