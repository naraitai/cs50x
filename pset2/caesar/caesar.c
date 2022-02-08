/*---------------------------------
Task 3 of 4

Brief
- Implement Ceasar's cipher
- Ceasar's cipher
    - Encrypts message by shifting each letter
    - Letter is shifted by a specified key
    - Shifted letters wrap round back to the beginning of the alphabet
- Accept key as a command line argument (not negative integer)
- Prompt for plaintext
- Output ciphertext
-  Ensure it is case-sensitive

Expected output

    plaintext: HELLO
    ciphertext: URYYB

Distribution code
- None

Non Standard Libraries:
- cs50.h

Key concept:
- Encryption
- Command line arguments
-----------------------------------*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Take Command Line Arguments (only 1)
int main(int argc, string argv[])
{
    //Check number of arguments
    if (argc  < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //Check for non-digit input
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //Convert argument to integer
        int key = atoi(argv[1]);
        
        //Prompt for plaintext message
        string plaintext = get_string("plaintext: ");
        
        //Start ciphertext message
        printf("ciphertext: ");
        
        //Loop plaintext
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char c = plaintext[i];
            
            //Check i is letter and is uppercase
            if (isalpha(c) && isupper(c))
            {
                //Convert to 0 index and wrap round if needed (upper)
                c = (c - 65 + key) % 26 + 65;
                printf("%c", c); 
            }
            
            //Check i is letter and is lowercase
            else if (isalpha(c) && islower(c))
            {
                //Convert to 0 index and wrap round if needed (lower)
                c = (c - 97 + key) % 26 + 97;
                printf("%c", c);
            }
            
            //Check i is not a letter and print unchanged
            else
            {
                printf("%c", c);
            }
        }
        
        //Finish cyphertext build
        printf("\n");
    }
}