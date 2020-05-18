#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user for input
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}
