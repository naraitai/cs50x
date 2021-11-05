#include <stdio.h>
#include <cs50.h>

void blocks(int n);
void spaces(int n);

int main(void)
{
    //Prompt user to define pyramid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    
    //Using height loop until pyramid built
    for (int i = 0; i < height; i++)
    {
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        printf("#");
        for (int j = 0; j < i; j++)
        {            
            printf("#");
        }
        printf("\n");
    }
}