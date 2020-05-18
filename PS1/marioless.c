#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void pyramid(int m);

int main(void)
{
    int height = get_height("Height: ");
    pyramid(height);
}

//Prompt user for a positive integer between 1 and 8
int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}

//Prints right-handed pyramid of hashes according to user's input
void pyramid(int m)
{
    //Iteration for number of rows
    for (int i = 1; i <= m; i++)
    {
        //Iteration for number of spaces per row
        for (int k = m; k > i; k--)
        {
            printf(" ");
        }
        //Iteration for number of hashes per row
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
