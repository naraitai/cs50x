/*---------------------------------
Task 1 of 6

Brief
- Prompt user for name
- Print message greeting user

Expected output

     hello, <user input name>

Distribution code
- None

Non Standard Libraries:
- cs50.h

Key concept:
- Basic C syntax
-----------------------------------*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt and store users name.
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}