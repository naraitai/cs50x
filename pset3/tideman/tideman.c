/*---------------------------------
Task 4 of 4

Brief
- Implement a program that runs a Tideman election
- Tideman election
    - a.k.a ranked pairs voting system
    - Based on the winner of head-to-head elections
    - Determine for each pair of candidate the preferred candidate
    - Record margin by which they were preferred
    - Sort the pairs in decreasing order base on margin
    - Start from strongest pair lock in pairs of candidates
    - Do not create a cycle in the graph.
- Implemented by creating graph
- This records who wins against whom
- Source of graph is the election winner
- Complete vote function
    - Takes rank, name and ranks as arguments
    - If name is a candidate update the ranks array
- Complete record_preferences function
    - Called once for each voter
    - Takes ranks array as argument
    - Updates global preferences array adding the current voter's preference
- Complete add_pairs function
    - Add pairs of candidates where one candidate is preferred
    - Ties are not added
    - Update pair_count
- Complete sort_pairs function
    - Sort pairs array in decreasing order of strength of victory
- Complete lock_pairs function
    - Creates locked graph
    - Add all edges (showing winner of pairs)
    - Does not add if cycle would be created
- Complete print_winner function
    - Print out name of the candidate with is the source of the graph
    - Assume only one source

Expected output

    ./tideman Alice Bob Charlie
    Number of voters: 5
    Rank 1: Alice
    Rank 2: Charlie
    Rank 3: Bob

    ...
    
    Charlie

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

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int start, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}
/*>>>>>>Distribution code end<<<<<<*/

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop across every voter entry to check if valid and store in ranks array
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Loop across each element in ranks array add 1 to correct column for every candidate lower in array
    for (int i = 0; i < candidate_count; i++)
    {
        preferences[ranks[i]][ranks[i]] += 0;
        
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Loop through preferences array and find winner-loser pairs and add them to pairs array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Bubble sort implementation. Find margin for i and i + 1. If i's margin is smaller buddle to the right. Continue until largest margin first
    for (int i = 0; i < pair_count; i++)
    {
        int margin_i = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];

        for (int j = i + 1; j < pair_count; j++)
        {
            int margin_j = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

            if (margin_i < margin_j)
            {
                pair swap = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = swap;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Loop through pairs array locking non-cyclical pairs into 2D array. Call recursive function to achieve this.
    for (int i = 0; i < pair_count; i++)
    {
        if (!check_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // Loop through each column of the locked array. Counting number of locks in column. If 0 candidate has no edges and wins. Print winner(s). 
    for (int i = 0; i < candidate_count; i++)
    {
        int winner = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                winner++;
            }
        }
        if (winner == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
}

// Recursive function to check for cycle
bool check_cycle(int winner, int loser)
{
    if (winner == loser)
    {
        return true;
    }

    for (int i = 0; i < pair_count; i++)
    {
        if (locked[loser][i] == true)
        {
            if (check_cycle(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}