# Harvard CS50x 

## Summary
Introduction to the intellectual enterprises of computer science and the art of programming. 
This course teaches students how to think algorithmically and solve problems efficiently. 
Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web programming. 
Languages include C, Python, and SQL plus HTML, CSS, and JavaScript. 
Problem sets inspired by the arts, humanities, social sciences, and sciences. 
Course culminates in a final project.

## Problem Set 1 (C)
<details>
    <summary>Expand</summary>

### 1. Hello
<details>
    <summary>Info</summary>
    
#### Brief
Print out message greeting user.
#### Expected output
    hello, {user input name}
</details>

### 2. Population
<details>
    <summary>Info</summary>
    
#### Brief
Determine time it takes for a puplation to reach a sepcified size.
Assume n / 3 are born each year and n / 4 die each year. Take user input start and end size and output the number of years it would take to reach the specified population.
#### Expected output
    Start size: 100
    End size: 200
    Years: 9
</details>
    
### 3. Mario (Less)
<details>
    <summary>Info</summary>
    
#### Brief
Print out a pyramid of hashes. The pyramid height is set by the user, but must be between 1 and 8. The pyramid should align to the right.
#### Expected output
         #
        ##
       ###
      ####
     #####
    ######
</details>
    
### 4. Mario (More)
<details>
    <summary>Info</summary>
    
#### Brief
Similar to mario less. Create a full pyramid of hashes. The pyramid height is set by the user between 1 and 8. 
#### Expected output
         # #
        ## ##
       ### ###
      #### ####
     ##### #####
    ###### ######
</details>
    
### 5. Cash
<details>
    <summary>Info</summary>
    
#### Brief
Calculate minimum number of coins required to make up change. Take user input change due amount. Print minimum number of coins required (US coinage).
#### Expected output
    Change owed: 0.41
    4
</details>
    
### 6. Credit
<details>
    <summary>Info</summary>
    
#### Brief
Implement Luhn's Algorithm to validate input credit card number. Prompt user for a credit card number. Return whether the number is American Express, Mastercard, Visa 
or invalid.
- Algorithm
  - Start with the second-to-last digit, multiply every other digit by 2.
  - Add these results together
  - Add all remaining numbers together
  - Add these two sums together
  - If last digit is 0 the number is valid
#### Expected output
    Number: 4003600000000014
    VISA    
</details>
</details>

## Problem Set 2 (Arrays)
<details>
    <summary>Expand</summary>
    
### 1. Scrabble
<details>
    <summary>Info</summary>
    
#### Brief
Determine which of two Scrabble words scores highest.
#### Expected output
    Player 1: Computer
    Player 2: Science
    Player 1 wins!
</details>

### 2. Readability
<details>
    <summary>Info</summary>
    
#### Brief
Implement Coleman-Liau formula. Prompt user for string. Count number of letters, words and sentences in text. Output 'Grade X'
- Formula
    - index = 0.0588 * L - 0.296 * S - 15.8
    - L = average number of letter per 100 words
    - S = average number of sentence per 100 words
#### Expected output
    Text: <user input text>
    Grade <index of text>
</details>

### 3. Caesar
<details>
    <summary>Info</summary>
    
#### Brief
Implement Ceasar's cipher.
- Ceasar's cipher
    - Encrypts message by shifting each letter
    - Letter is shifted by a specified key
    - Shifted letters wrap round back to the beginning of the alphabet
#### Expected output
    plaintext: HELLO
    ciphertext: URYYB
</details>

### 4. Substitution
<details>
    <summary>Info</summary>
    
#### Brief
Implement a substitution cipher
- Substitution cipher
    - Replace every letter with another letter. 
    - Letters are replaced based on a key 
#### Expected output
    ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
    plaintext: hello, world
    ciphertext: jrssb, ybwsp
</details>    
</details>
    
## Problem Set 3 (Algorithms)
<details>
    <summary>Expand</summary>
    
### 1. Sort
<details>
    <summary>Info</summary>
    
#### Brief
Analyse three sorting programs to determine which algorithm they use based on run-time.
</details>
    
### 2. Plurality
<details>
    <summary>Info</summary>
    
#### Brief
Implement a program that runs a plurality election
- Plurality election
    - a.k.a first-past-the-post
    - Each voter votes for one candidate
    - Whichever has the greatest number of votes is declared the winner
#### Expected output
    ./plurality Alice Bob
    Number of voters: 3
    Vote: Alice
    Vote: Bob
    Vote: Alice
    Alice
</details>
    
### 3. Runoff
<details>
    <summary>Info</summary>

#### Brief
Implement a program that runs a runoff election
- Runoff election
    - a.k.a ranked-choice voting system
    - Voters can rank candidates in order of preference
    - Candiate with majority of first preference wins
    - If no candidate has majority candidate with fewest votes is elmininated
    - Voters who chose eliminated candidate as first choice have second choice used
    - This repeats until a candidate has a majority
#### Expected output
    ./runoff Alice Bob Charlie
    Number of voters: 5
    Rank 1: Alice
    Rank 2: Charlie
    Rank 3: Bob
    ...
    Alice
</details>

### 4. Tideman 
<details>
    <summary>Info</summary>
    
#### Brief
Implement a program that runs a Tideman election
- Tideman election
    - a.k.a ranked pairs voting system
    - Based on the winner of head-to-head elections
    - Determine for each pair of candidate the preferred candidate
    - Record margin by which they were preferred
    - Sort the pairs in decreasing order base on margin
    - Start from strongest pair lock in pairs of candidates
    - Do not create a cycle in the graph.
#### Expected output
    ./tideman Alice Bob Charlie
    Number of voters: 5
    Rank 1: Alice
    Rank 2: Charlie
    Rank 3: Bob
    ...
    Charlie
</details>
</details>
    
## Problem Set 4 (Memory)  
<details>
    <summary>Expand</summary>

### 1. Volume
<details>
    <summary>Info</summary>
    
#### Brief
Write a program that modifies audio file's volume. Do not leak any memory
#### Expected output
    ./volumn input.wav output.wav 2.0
</details>
    
### 2. Filter (Less)
<details>
    <summary>Info</summary>
     
#### Brief
Write a program that applies filters to BMPs. Implement function in helpers.c file. Complete grayscale, sepia, reflect and blur filter functions.
#### Expected output
    ./filter -r image.bmp reflected.bmp
</details>

### 3. Filter (More)
<details>
    <summary>Info</summary>
   
#### Brief
Write a program that applies filters to BMPs. Implement functions in helpers.c file. Complete grayscale, reflect, blur and edges filter functions.
#### Expected output
    ./filter -r image.bmp reflected.bmp
</details>

### 4. Recover
<details>
    <summary>Info</summary>
    
#### Brief
Write a program that recovers JPEGs from a forensic image. Generate each .jpeg image found in file. Do not leak any memory
</details>
</details>
    
## Problem Set 5 (Data Structures)
<details>
    <summary>Expand</summary>    
    
### 1. Inheritance
<details>
    <summary>Info</summary>
    
#### Brief
Simulate the inheritance of blood types for each member of a family. Complete inheritance.c
#### Expected output
    Generation 0, blood type OO
        Generation 1, blood type AO
        Generation 2, blood type BO
    Generation 1, blood type OB
        Generation 2, blood type AO
        Generation 2, blood type BO
</details>
    
### 2. Speller
<details>
    <summary>Info</summary>
    
#### Brief
Implement a program the spell-checks a file using a hash table. Implement as efficiently as possible.
#### Expected output
    ./speller texts/lalaland.txt
    MISSPELLED WORDS
    [...]
    AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
    [...]
    Shangri
    [...]
    fianc
    [...]
    Sebastian's
    [...]

    WORDS MISSPELLED:
    WORDS IN DICTIONARY:
    WORDS IN TEXT:
    TIME IN load:
    TIME IN check:
    TIME IN size:
    TIME IN unload:
    TIME IN TOTAL:
</details>  
</details>
    
## Problem Set 6 (Python)
<details>
    <summary>Expand</summary>

### 1. World Cup
<details>
    <summary>Info</summary>

#### Brief
Write program that simulates the FIFA World Cup.
#### Expected output
    python tournament.py 2018m.csv
    Belgium: 20.9% chance of winning
    Brazil: 20.3% change of winning
    ...
</details>  
    
### 2. Hello
<details>
    <summary>Info</summary>

#### Brief
Python version of pset1 hello.c. Greet user.
#### Expected output
    What is your name?
    David
    hello, David
</details>
    
### 3. Mario (Less)
<details>
    <summary>Info</summary>

#### Brief
Python version of pset1 mario_less.c. Print a right aligned pyramid of hashes
#### Expected output
             #
            ##
           ###
          ####
         #####
        ######
</details>  

### 4. Mario (More)
<details>
    <summary>Info</summary>
    
#### Brief
Python version of pset1 mario_more. Print a full pyramid of hashes
#### Expected output
             # #
            ## ##
           ### ###
          #### ####
         ##### #####
        ###### ######
</details>  
    
### 5. Cash
<details>
    <summary>Info</summary>
    
#### Brief
Python version of pset1 cash.c. Return minimum number of coins needed to give change (US coinage)
#### Expected output
    Change owed: 0.41
    4
</details>
    
### 6. Credit
<details>
    <summary>Info</summary>
    
#### Brief
Python version of pset1 credit.c. Implement Luhn's algorithm. Validate a user input credit card number
#### Expected output
    Number: 378282246310005
    AMEX
</details>  

### 7. Readability
<details>
    <summary>Info</summary>
   
#### Brief
Python version of pset2 readability. Compute approximate grade level needed to understand a text. Implement the Coleman-Liau index
#### Expected output
    Text: <user input text>
    Grade <integer>
</details> 
    
### 8. DNA
<details>
    <summary>Info</summary>
    
#### Brief
Implement a program that identifies a person based on their DNA. Use Short Tandem Repeats (STRs) to find matches
#### Expected output
    python dna.py databases/large.csv sequences/5.txt
    Lavender
</details> 
</details> 

    
    
