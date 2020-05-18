#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// A program that tests readability of a text through the Coleman-Liau index
// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average # of letters per 100 words
// and S is the average # of sentences per 100 words

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: "); // Gets text input from user

    // Stores counted letters, words, and sentences into variables
    int l = count_letters(text), w = count_words(text) + 1, s  = count_sentences(text);

    // L = ave # of letters per 100 words, S = ave # of sentences per 100 words
    float L = (l / (float)w) * 100, S = (s / (float)w) * 100;

    // Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index)); // Rounds up computed index and prints as integer
    }

}

// Counts number of letters in text
int count_letters(string text)
{

    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // Loops through each char in text
    {
        if (isalpha(text[i]) != 0) // Checks if char is an alphabetic char
        {
            count++; // Counts every alphabetic char found
        }
    }
    return count; // Returns number of letters in text
}

// Counts number of words in text
int count_words(string text)
{

    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // Loops through each char in text
    {
        if (isspace(text[i]) != 0) // Checks if char is a white-space char
        {
            count++; // Counts every white-space char found
        }
    }
    return count; // Returns number of spaces in text
}

// Counts number of sentences in text
int count_sentences(string text)
{

    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // Loops through each char in text
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') // Checks if char is a '.', '?', or '!'
        {
            count++; // Counts every '.', '?' '!' char found
        }
    }
    return count; // Returns number of punctuations in text
}