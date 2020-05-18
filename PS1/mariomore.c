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

void hash(int m)
{
    //Iteration for number of hashes
    for (int j = 1; j <= m; j++)
    {
        printf("#");
    }
}

//Prints pyramid of hashes according to user's input
void pyramid(int p)
{
    //Iteration for number of rows
    for (int i = 1; i <= p; i++)
    {
        //Iteration for number of spaces per row
        for (int k = p; k > i; k--)
        {
            printf(" ");
        }
        hash(i); //Right-handed pyramid
        printf("  "); //Space gap
        hash(i); //Left-handed pyramid
        printf("\n");
    }
}
