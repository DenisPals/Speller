// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <strings.h>
#include "dictionary.h"



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N]; // Amount of buckets in hash table - My own note

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    bool check = false;
    unsigned int h;
    h = hash(word);

    for (node *tmp = table[h]; tmp->next != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            check = true;
        }
    }
    return check;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Variables to calculate hash index
    int i = 0;
    int u = 0;

    // Cover case of only one letter in word to hash
    if (strlen(word) == 1 || word[1] == 39)
    {
        i = toupper(word[0]) - 'A';
    }
    else
    {
        // Take first and second letters alpabetical index (0 - 25)
        i = toupper(word[0]) - 'A';
        u = toupper(word[1]) - 'A';
    }
    // Multiply the second letters alpabethical index with 26 and add to first letters
    u = u * 26;
    i += u;

    return i;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary and create buffer
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char *buffer = malloc(sizeof(LENGTH) + 1);
    if (buffer == NULL)
    {
        printf("Memory error\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        if (sizeof(table[i]) < sizeof(node))
        {
            table[i] = malloc(sizeof(node));
            table[i]->next = NULL;
            if (table[i] == NULL)
            {
                printf("Memory error in buckets\n");
            }
        }
    }

    // Load and hash word
    unsigned int i = 0;
    while (fscanf(file, "%s", buffer) == 1)
    {
        // Obtain hashvalue
        char *word = malloc(46 * sizeof(char));
        strcpy(word, buffer);
        i = hash(word);

        // Create node and implement into hash table
        node *coufit = malloc(sizeof(node));
        node *wordimp = malloc(sizeof(node));
        strcpy(wordimp->word, word);
        wordimp->next = NULL;
        if (table[i]->next == NULL)
        {
            strcpy(table[i]->word, word);
            table[i]->next = coufit;
            free(wordimp);
        }
        else if (table[i]->next == coufit)
        {
            table[i]->next = wordimp;
            free(coufit);
        }
        if (table[i]->next != NULL && table[i]->next != coufit)
        {
            node *tmp = table[i]->next;
            table[i]->next = wordimp;
            wordimp->next = tmp;
        }
    }

    // TEMPORARY CHANGE OF FIRST NODE
    char *a = "a";
    char *b = "lcanoconiosis";
    if (strcmp(table[0]->word, b) == 0)
    {
        strcpy(table[0]->word, a);
    }

    // TESTING LOOP
    for (node *t = table[0]; t->next != NULL; t = t->next)
    {
        printf("%s\n", t->word);
    }

    free(buffer);
    fclose(file);
    return true;   // CHANGE BACK TO TRUE
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int counter = 0;
    int counterx = 0;

    for (int y = 0; y < N; y++)
    {
        for (node *t = table[y]; t->next != NULL; t = t->next)
        {
            counterx++;
        }
    }

    return counterx;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        for (node *cursor = table[i], *delete; cursor->next != NULL; cursor = cursor->next)
        {
            delete = cursor;
            free(delete);
        }
    }
    return true;
}
