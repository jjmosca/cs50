#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        // Exits program if user inputs no argument or more than one argument
        // Or if user-input argument does not have 26 chars
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (isalpha(argv[1][i]) == 0) // Exits program if user-input argument contains a non-alphabetic char
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            for (int m = i + 1; m < 26; m++)
            {
                if (argv[1][i] == argv[1][m]) // Exits program if user-input argument contains duplicate chars
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }

        // Main program if user-input argument is valid

        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int j = 0, n = strlen(plain); j < n; j++) // Loops through each char in plaintext
        {
            if (isalpha(plain[j])) // Checks if char is an alphabetic char
            {
                if (isupper(plain[j])) // Checks if char is uppercase
                {
                    int temp1 = plain[j] - 65; // Converts A-Z to 0-26 index
                    printf("%c", toupper(argv[1][temp1]));
                }
                else // If char is lowercase
                {
                    int temp2 = plain[j] - 97; // Converts a-z to 0-26 index
                    printf("%c", tolower(argv[1][temp2]));
                }
            }
            else // If char is not an alphabetic char
            {
                printf("%c", plain[j]); // Print as is
            }
        }
        printf("\n");
        return 0;
    }
}