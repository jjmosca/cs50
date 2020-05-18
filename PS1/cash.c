#include <math.h>
#include <cs50.h>
#include <stdio.h>

float get_change(string prompt);

int main(void)
{
    float dollar = get_change("Change owed: ");
    int coins = round(dollar * 100); // Converts dollar input to cents value
    int i = 0;
    // Change owed will be subtracted from the highest value possible (25 cents) 
    // to the lowest (1 cent) until value is zero
    while (coins > 0)
    {
        if (coins >= 25)
        {
            coins -= 25;
        }
        else if (coins >= 10)
        {
            coins -= 10;
        }
        else if (coins >= 5)
        {
            coins -= 5;
        }
        else
        {
            coins -= 1;
        }
        i++; // Counter of coins used for change
    }
    printf("%i\n", i); // Show number of coins for change owed
}

// Prompt user for a positive input (accepts floating-point values)
float get_change(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n <= 0);
    return n;
}
