#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //Prompt user to enter number until valid entry.
    long input;
    do
    {
        input = get_long("Number: ");
    }
    while (input <= 0);
    
    //Find length of user input number
    long credit = input;
    int length;
    for (length = 0; credit; length++)
    {
        credit /= 10;
    }
    
    //Loop to calculate check sum
    credit = input;
    int check_sum = 0;
    for (int i = 1; i < length + 1; i++)
    {
        //Find every other digit starting from second to last digit and multiply by two
        if (i % 2 == 0)
        {
            int digit = (credit % 10) * 2;
            credit /= 10;
            
            //Add each digit of sums with multiple digits (after multiplied by two)
            if (digit > 9)
            {
                check_sum += digit % 10;
                digit /= 10;
                check_sum += digit % 10;
            }
            else
            {
                check_sum += digit;
            }
        }
        //Simply add every other digit from the last to the check sum
        else
        {
            check_sum += credit % 10;
            credit /= 10;
        }
    }
    
    //Find first two digits of user input number
    credit = input;
    while (credit >= 100)
    {
        credit /= 10;
    }
    
    //Determine if check sum is valid and which company card number is associated with.
    if (check_sum % 10 == 0)
    {
        if ((credit == 34 || credit == 37) && (length == 15))
        {
            printf("AMEX\n");
        }
        else if ((credit > 50 && credit < 56) && (length == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((credit > 39 && credit < 50) && (length == 13 || length == 16))
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