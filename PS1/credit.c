#include <math.h>
#include <cs50.h>
#include <stdio.h>

// AMEX: 15-digit; starts with 34 or 37
// MASTERCARD: 16-digit; starts with 51 to 55
// VISA: 13 & 16 digits; starts with 4

int check_sum(long num);
int get_length(long num);

int main(void)
{
    long card = get_long("Number: ");
    int n = get_length(card); // Gets length of card number
    if (check_sum(card) == 1) // Checks if result of function is 1 which implies validity
    {
        if (n == 15) // Checks if card number has 15 digits
        {
            // Checks if card number starts with 34 or 37
            if ((int)(card / pow(10, 13)) == 34 || (int)(card / pow(10, 13)) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            
        }
        else if (n == 16) // Checks if card number has 16 digits
        {
            // Checks if card number starts with 51, 52, 53, 54 or 55
            if ((int)(card / pow(10, 14)) > 50 && (int)(card / pow(10, 14)) < 56)
            {
                printf("MASTERCARD\n");
            }
            // Checks if card number starts with 4
            else if ((int)(card / pow(10, 15)) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n == 13) // Checks if card number has 13 digits
        {
            // Checks if card number starts with 4
            if ((int)(card / pow(10, 12)) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Luhn's Algorithm
int check_sum(long num)
{
    int i = 1, sume = 0, sumf = 0, sumo = 0;
    while (num)
    {
        if (i % 2 == 0) //even-placed digits
        {
            int e = (num % 10) * 2;
            if (e > 9) 
            {
                while (e)
                {
                    sumf += e % 10; // sum of each digit of products greater than 9
                    e /= 10;
                }
            }
            else
            {
                sume += e; // sum of digits less than 10
            }
        }
        else //odd-placed digits
        {
            int o = num % 10;
            sumo += o; // sum of odd-placed digits
        }
        num /= 10;
        i++;
    }
    if ((sume + sumf + sumo) % 10 == 0)
    {
        return 1; // Valid card number if result of sum modulo 10 is 0
    }
    else
    {
        return 0;
    }
}

// Gets length of card number
int get_length(long num)
{
    int i = 0;
    while (num)
    {
        num /= 10;
        i++;
    }
    return i;
}
