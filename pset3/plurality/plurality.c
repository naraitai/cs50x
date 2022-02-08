/*---------------------------------
Task 2 of 4

Brief
- Implement a program that runs a plurality election
- Plurality election
    - a.k.a first-past-the-post
    - Each voter votes for one candidate
    - Whichever has the greatest number of votes is declared the winner
- Complete vote function
    - Take single argument. The candidates name
    - Add vote to candidates total if there is a match
- Complete print_winner function
    - Print out name of candidate with most votes
    - Ties are possible. Output each tieing candidate

Expected output

    ./plurality Alice Bob
    Number of voters: 3
    Vote: Alice
    Vote: Bob
    Vote: Alice
    Alice

Distribution code
- Shown as follows 
    >>>>>Distribution code start<<<<<
    >>>>>>Distribution code end<<<<<<

Non Standard Libraries:
- cs50.h

Key concept:
- Algorithms
-----------------------------------*/

/*>>>>>Distribution code start<<<<<*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}
/*>>>>>>Distribution code end<<<<<<*/

// Update vote totals given a new vote
bool vote(string name)
{
    // Loop through candidates to find match and increment votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes ++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Loop over condiates to find winning vote count. Print winner(s)
    int winner = 0;
    for (int i = 0; i <= candidate_count; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }

    for (int i = 0; i <= candidate_count; i++)
    {
        if (candidates[i].votes == winner)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}