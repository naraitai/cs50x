/*---------------------------------
Task 1 of 2

Brief
- Simulare the inheritance of blood types for each member of a family
- Complete inheritance.c
- create_family function 
    - Allocates one person for each member of family
    - Returns pointer to youngest generation
- Assign alleles to each person
    - Generate random alleles for each for older generation
- Assign parents to each person
    - Oldest generation parents are NULL
- Allocate memory for a new person
- Assign parents recursively
- Return pointer for the person allocated
- free_family function
    - Accepts pointer to person
    - Free memory for that person
    - Free memory for all acnestors recursively

Expected output

    Generation 0, blood type OO
        Generation 1, blood type AO
        Generation 2, blood type BO
    Generation 1, blood type OB
        Generation 2, blood type AO
        Generation 2, blood type BO
    
Distribution code
- Shown as follows 
    >>>>>Distribution code start<<<<<
    >>>>>>Distribution code end<<<<<<

Key concept:
- Data structures
-----------------------------------*/

/*>>>>>Distribution code start<<<<<*/
// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

/*>>>>>>Distribution code end<<<<<<*/

// Create a new individual with `generations`
person *create_family(int generations)
{
    // Allocate memory for new person
    person *n = malloc(sizeof(person));


    // Generation with parent data
    if (generations > 1)
    {
        // Recursively create blood type histories for parents
        n->parents[0] = create_family(generations - 1);
        n->parents[1] = create_family(generations - 1);

        // Randomly assign child alleles based on parents
        n->alleles[0] = n->parents[0]->alleles[rand() % 2];
        n->alleles[1] = n->parents[1]->alleles[rand() % 2];

    }

    // Generation without parent data
    else
    {
        // Set parent pointers to NULL
        n->parents[0] = NULL;
        n->parents[1] = NULL;

        // Randomly assign alleles
        n->alleles[0] = random_allele();
        n->alleles[1] = random_allele();
    }

    // Return newly created person
    return n;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free child
    free(p);
}

/*>>>>>Distribution code start<<<<<*/
// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
/*>>>>>>Distribution code end<<<<<<*/
