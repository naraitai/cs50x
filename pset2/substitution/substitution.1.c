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
    
    //Encryption start
    
    //Get plaintext from user
    string plaintext = get_string("plaintext: ");
    
    //Start ciphertext build
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //Keep punctuation the same
        if (isalpha(plaintext[i]) == 0)
        {
            printf("%c", plaintext[i]);
        }
        //Maintain plaintext character case irrespective of key character case
        //Treatment of uppercase plaintext
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                if (isupper(argv))
            }
        }
        
        else if (isupper(plaintext[i]))
        {
            int index = (int)plaintext[i] - 65;
            //Upper plaintext and upper case key character
            if (isupper(argv[1][index]) > 0)
            {
                printf("%c", argv[1][index]);
            }
            //Upper plaintext and lower key character
            else
            {
                printf("%c", argv[1][index] - 32);
            }
        }
        //Treatment of lower case plaintext
        else
        {
            int index = (int)plaintext[i] - 97;
            //Lower case plaintext and lower case key character
            if (islower(argv[1][index]) > 0)
            {
                printf("%c", argv[1][index]);
            }
            //Lower case plaintext and upper case key character
            else
            {
                printf("%c", argv[1][index] + 32);
            }
        }
    }
    //Finish ciphertext build
    printf("\n");
    return 0;
}