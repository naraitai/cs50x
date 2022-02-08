/*---------------------------------
Task 4 of 4

Brief
- Implement a substitution cipher
- Substitution cipher
    - Replace every letter with another letter. 
    - Letters are replaced based on a key 
- Accept key as a command line argument (e.g. NQXPOMAFTRHLZGECYJIUWSKDVB)
- Prompt for plaintext
- Encrypt by substiution letters following input key. (e.g. A = N)
- Output ciphertext
- Preserve case and non-alphabetical characerts

Expected output

    ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
    plaintext: hello, world
    ciphertext: jrssb, ybwsp

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
#include <ctype.h>

//Take key as command line argument
int main(int argc, string argv[])
{
    
    //Command line argument validation
    //Only take 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    
    //Only take a key with a length of 26 characters
    else
    {
        int length = strlen(argv[1]);
        
        if (length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        
        //Key validation
        else
        {
            //Only take keys with only letters
            for (int i = 0; i < length; i++)
            {
                if (isdigit(argv[1][i]))
                {
                    printf("Key must only contain alphabetic characters.\n");
                    return 1;
                }
            }
            //Only take keys that don't repeat letters
            for (int i = 0; i < length - 1; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Key must not contain repreated characters.\n");
                        return 1;
                    }
                }
            }
        }
    }
    
    //Start enciphering
    
    //Get plaintext from user
    string plaintext = get_string("plaintext: ");
    
    //Create cipher text
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //Check if plaintext character is alphabetical. Also maintain case and swap for key character
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 65;
                
                if (islower(argv[1][index]))
                {
                    printf("%c", argv[1][index] - 32);
                }
                else
                {
                    printf("%c", argv[1][index]);
                }
            }
            else
            {
                int index = plaintext[i] - 97;
                
                if (isupper(argv[1][index]))
                {
                    printf("%c", argv[1][index] + 32);
                }
                else
                {
                    printf("%c", argv[1][index]);
                }
            }
        }
        //Print non-alphabetical characters unchanged
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
        
    return 0;
}