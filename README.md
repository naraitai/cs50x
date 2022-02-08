# Harvard CS50x 

## Summary
Introduction to the intellectual enterprises of computer science and the art of programming. 
This course teaches students how to think algorithmically and solve problems efficiently. 
Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, software engineering, and web programming. 
Languages include C, Python, and SQL plus HTML, CSS, and JavaScript. 
Problem sets inspired by the arts, humanities, social sciences, and sciences. 
Course culminates in a final project.

## Problem Set 1

### 1. Hello (C)
#### Brief
Print out message greeting user.
#### Expected output
    hello, {user input name}

### 2. Population
#### Brief
Determine time it takes for a puplation to reach a sepcified size.
Assume n / 3 are born each year and n / 4 die each year. Take user input start and end size and output the number of years it would take to reach the specified population.
#### Expected output
    Start size: 100
    End size: 200
    Years: 9

### 3. Mario (Less)
#### Brief
Print out a pyramid of hashes. The pyramid height is set by the user, but must be between 1 and 8. The pyramid should align to the right.
#### Expected output
         #
        ##
       ###
      ####
     #####
    ######

### 4. Mario (More)
#### Brief
Similar to mario less. Create a full pyramid of hashes. The pyramid height is set by the user between 1 and 8. 
#### Expected output
         # #
        ## ##
       ### ###
      #### ####
     ##### #####
    ###### ######

### 5. Cash
#### Brief
Calculate minimum number of coins required to make up change. Take user input change due amount. Print minimum number of coins required (US coinage).
#### Expected output
    Change owed: 0.41
    4

### 6. Credit
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
