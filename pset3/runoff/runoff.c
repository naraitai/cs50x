/*---------------------------------
Task 3 of 4

Brief
- Implement a program that runs a runoff election
- Runoff election
    - a.k.a ranked-choice voting system
    - Voters can rank candidates in order of preference
    - Candiate with majority of first preference wins
    - If no candidate has majority candidate with fewest votes is elmininated
    - Voters who chose eliminated candidate as first choice have second choice used
    - This repeats until a candidate has a majority
- Candidates tieing for last place are all elminated
- All voters should rank all candidates
- Complete vote function
    - Takes voter, rank and name as arguments
    - If name matches valid candidate update preference array
- Complete tabulate function
    - Updates number of votes each candidate has
- Complete print_winner function
    - Print winner and function returns true if candidate has majority
    - If no winner yet return false
- Complete find_min function
    - Returns minimum vote total for candidates in election
- Complete is_tie function
    - Takes min as argument. This is the minimum number of votes
    - Return true if every candidate remaining has the same number of votes
    - Return false otherwise
- Complete eliminate function
    - Takes min as ragument. This is the minimum number of votes
    - Eliminate the candidate(s) who has the minimum number of votes

Expected output

    ./runoff Alice Bob Charlie
    Number of voters: 5
    Rank 1: Alice
    Rank 2: Charlie
    Rank 3: Bob

    ...
    
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

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}
/*>>>>>>Distribution code end<<<<<<*/

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Store valid votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through each of voters rank
        for (int j =  0; j < candidate_count; j++)
        {
            // Check if candidate is not eliminated
            if (!candidates[preferences[i][j]].eliminated)
            {
                // Add vote to candidates total and end
                candidates[preferences[i][j]].votes ++;
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Check for and print winner
    int half_votes = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > half_votes)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Find lowest number of votes.
    // Set min to all votes
    int min = voter_count;

    //Loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //If candidates is not eliminated and has fewer votes than current min
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            //Min becomes this number of votes
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Track number of ties and number of not eliminated candidates
    int tie = 0;
    int not_eliminated = 0;
    //Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //If the candidate is not eliminated add one tracker
        if (!candidates[i].eliminated)
        {
            not_eliminated ++;

            // If candidate also has the min number of votes add one to tie tracker
            if (candidates[i].votes == min)
            {
                tie ++;
            }
        }
    }
    // If tie tracker and remaining candidates tracker is equal, there is a tie
    if (tie == not_eliminated)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Loop through remaining candidates and eliminate all with minimum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}