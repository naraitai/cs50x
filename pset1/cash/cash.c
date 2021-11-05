#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Define change amounts
    int quarter, dime, nickel, penny;
    quarter = 25;
    dime = 10;
    nickel = 5;
    penny = 1;

    //Prompt user for input
    float input;
    do
    {
        input = get_float("Change owed: ");
    }
    while (input <= 0);

    //Turn float to int to avoid imprescission
    int cents = round(input * 100);

    //Declare variable to track number of coins
    int coin = 0;

    //Calculate change starting with largest coin
    while (cents > 0)
    {
        if (cents - quarter >= 0)
        {
            cents -= quarter;
            coin++;
        }
        else if (cents - dime >= 0)
        {
            cents -= dime;
            coin++;
        }
        else if (cents - nickel >= 0)
        {
            cents -= nickel;
            coin++;
        }
        else
        {
            cents -= penny;
            coin++;
        }
    }
    
    //Display the coin count
    printf("%i\n", coin);
}