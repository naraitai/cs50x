/*---------------------------------
Task 1 of 4

Brief
- Determine which of two Scrabble words scores highest
- Print Player 1 wins! / Player 2 wins! / Tie!

Expected output

    Player 1: Computer
    Player 2: Science
    Player 1 wins!

Distribution code
- Shown as follows 
    >>>>>Distribution code start<<<<<
    >>>>>>Distribution code end<<<<<<

Non Standard Libraries:
- cs50.h

Key concept:
- Arrays
-----------------------------------*/

/*>>>>>Distribution code start<<<<<*/
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
/*>>>>>>Distribution code end<<<<<<*/

#include <ctype.h>

/*>>>>>Distribution code start<<<<<*/
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
/*>>>>>>Distribution code end<<<<<<*/

    // Print the winner
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    //Compute and return score for string
    int score = 0;
    
    for (int i = 0, length = strlen(word); i <= length; i++)
    {
        if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
        else if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
    }
    return score;
}