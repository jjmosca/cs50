#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) // Exits program if user inputs no argument or more than one argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0) // Exits program if user-input argument is not an integer
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Main program if user-input argument is valid

        int k = atoi(argv[1]); // Converts user-input argument from a string to an integer

        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int j = 0, n = strlen(plain); j < n; j++) // Loops through each char in plaintext
        {
            if (isalpha(plain[j])) // Checks if char is an alphabetic char
            {
                if (isupper(plain[j])) // Checks if char is uppercase
                {
                    int temp1 = (plain[j] - 65 + k) % 26; // Wraps around only A-Z
                    printf("%c", temp1 + 65);
                }
                else // If char is lowercase
                {
                    int temp2 = (plain[j] - 97 + k) % 26; // Wraps around only a-z
                    printf("%c", temp2 + 97);
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