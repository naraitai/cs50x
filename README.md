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

## Problem Set 2 (C)
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
