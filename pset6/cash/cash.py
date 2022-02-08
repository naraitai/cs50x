"""---------------------------------
Task 5 of 8

Brief
- Python version of pset1 cash.c
- Return minimum number of coins needed to give change (US coinage)

Expected output
     
    Change owed: 0.41
    4
    
Distribution code
- None

None Standard Libraries
- cs50

Key concept:
- Nested for loops
-----------------------------------"""

from cs50 import get_float

# Dictionary of coins and their values
coins = {
    "quarter": 25,
    "dime": 10,
    "nickel": 5,
    "penny": 1,
}

# Prompt until positive number is input
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# Float to int to avoid imprescission
cents = round(change * 100)

# Set counter and loop until 0
count = 0
while cents > 0:
    
    if cents - coins["quarter"] >= 0:
        cents -= coins["quarter"]
        count += 1
        
    elif cents - coins["dime"] >= 0:
        cents -= coins["dime"]
        count += 1
        
    elif cents - coins["nickel"] >= 0:
        cents -= coins["nickel"]
        count += 1
    
    else:
        cents -= coins["penny"]
        count += 1
        
# Display the minimum nuber of coins needed
print(count)
