/*---------------------------------
Task 2 of 6

Brief
- Determine time it takes for a puplation to reach a sepcified size.
- n / 3 are born each year
- n / 4 die each year
- Take user input start and end size
- Ouput number of years to reach specified population

Expected output

    Start size: 100
    End size: 200
    Years: 9

Distribution code
- Shown as follows 
    >>>>>Distribution code start<<<<<
    >>>>>>Distribution code end<<<<<<

Non Standard Libraries:
- cs50.h

Key concept:
- Basic C syntax
-----------------------------------*/

/*>>>>>Distribution code start<<<<<*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
/*>>>>>>Distribution code end<<<<<<*/

    //Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    // Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    
    // Calculate number of years until we reach threshold
    int years = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    
    // Print number of yours
    printf("Years: %i\n", years);
}