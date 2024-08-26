// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// No of buckets in hash table
const unsigned int N = 1000;

unsigned int hash_value;
unsigned int word_count;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Getting the hash value
    hash_value = hash(word);

    node *ptr = table[hash_value];

    while (ptr != NULL)
    {
        // Checks if the word is a match
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        // Moves the pointer to the next node
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Declares word
    char word[LENGTH + 1];

    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        fclose(source);
        return false;
    }

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // unload memory
            return false;
        }
        // Copy word into node
        strcpy(n->word, word);

        // Hashing the word to get the hash value
        hash_value = hash(n->word);

        // Add each word to the hash table
        n->next = table[hash_value];

        // insert into list
        table[hash_value] = n;

        // Keeps track of the word count
        word_count++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // Set's the pointer to the start of the Linked list
        node *ptr = table[i];

        while (ptr != NULL)
        {
            node *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
        free(ptr);
    }
    return true;
}
