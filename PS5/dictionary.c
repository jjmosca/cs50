// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int buckets = 65536;

// Hash table
node *hashtable[buckets];

// Number of words in dictionary
unsigned long counter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Convert word into lowercase equivalent
    int len = strlen(word);
    char lowercase[len + 1];
    for (int i = 0; i < len; i++)
    {
        lowercase[i] = tolower(word[i]);
    }
    // Indicates end of string
    lowercase[len] = '\0';

    // Initialize cursor to nodes in hashtable
    node *cursor = hashtable[hash(lowercase)];

    // Look through each dictionary word
    while (cursor != NULL)
    {
        // Compare word and dictionary word (case insensitive)
        if (strcasecmp(lowercase, cursor->word) == 0)
        {
            return true;
        }

        // Move to next dictionary word
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
// from https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
unsigned int hash(const char *word)
{
    unsigned int hash = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        hash = (hash << 2) ^ word[i];
    }

    return hash % buckets;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fp;

    // Open dictionary file
    fp = fopen(dictionary, "r");

    // Exit if dictionary file is non-existent
    if (fp == NULL)
    {
        fprintf(stderr, "File not found.\n");
        unload();
        return false;
    }

    // Initialize variable for dictionary word
    char buff[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(fp, "%s", buff) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        // Copy dictionary word into node
        strcpy(n->word, buff);

        // Hash node and store hash value
        int index = hash(n->word);

        // Insert node into hashtable
        n->next = hashtable[index];
        hashtable[index] = n;

        // Count number of words loaded from dictionary
        counter++;
    }

    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < buckets; i++)
    {
        // Initialize cursor to header
        node *cursor = hashtable[i];

        // Look through each dictionary word
        while (cursor != NULL)
        {
            // Set temporary cursor
            node *temp = cursor;

            // Move to next node
            cursor = cursor->next;

            // Free temporary cursor
            free(temp);
        }

        // Free header cursor
        free(cursor);
    }

    return true;
}
