#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt and store users name.
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}