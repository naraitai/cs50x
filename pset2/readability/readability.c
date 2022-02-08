/*---------------------------------
Task 2 of 4

Brief
- Implement Coleman-Liau formula
- Formula
    - index = 0.0588 * L - 0.296 * S - 15.8
    - L = average number of letter per 100 words
    - S = average number of sentence per 100 words
- Prompt user for string
- Count number of letters, words and sentences in text
- Output 'Grade X'
- If index is 16+ output 'Grade 16+'
- If index is less than 1 output 'Before Grade 1'
- For this task a word is any sequence of characters separated by a space
- For this task any sequence ending with . or ! or ? is a sentence

Expected output

    Text: <user input text>
    Grade <index of text>

Distribution code
- None

Non Standard Libraries:
- cs50.h

Key concept:
- Arrays (strings as arrays of chars)
-----------------------------------*/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Functions to parse input
int count_letters(string x);
int count_words(string x);
int count_sentences(string x);

int main(void)
{
    //Prompt and store user input
    string input = get_string("Text: ");

    //Get number of letters in input as float
    float letters = (float)count_letters(input);
    
    //Get number of words in input as float
    float words = (float)count_words(input);
    
    //Get number of sentences in input as float
    float sentences = (float)count_sentences(input);
    
    //Use words to get scale to 100 and to calculate Coleman-Liau Index, finally rounding the result
    int index = round(0.0588 * (100 / words * letters) - 0.296 * (100 / words * sentences) - 15.8);
    
    //Detemine grade level using above index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Function that returns number of letters in input as an integer
int count_letters(string x)
{
    int letters = 0;

    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isalpha(x[i]))
        {
            letters++;
        }
    }
    return letters;
}

//Function that returns number of words in input as an integer
int count_words(string x)
{
    int words = 0;
    
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isspace(x[i]))
        {
            words++;
        }
    }
    
    words += 1;
    
    return words;
}

//Function that returns number of sentences in input as an integer
int count_sentences(string x)
{
    int sentences = 0;
    
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}