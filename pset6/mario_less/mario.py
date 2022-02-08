"""---------------------------------
Task 3 of 8

Brief
- Python version of pset1 mario_less.c
- Print a right aligned pyramid of hashes

Expected output
     
     #
    ##
   ###
  ####
 #####
######
    
Distribution code
- None

None Standard Libraries
- cs50

Key concept:
- Nested for loops
-----------------------------------"""

from cs50 import get_int

# Prompt for a pyramid between 1 and 8
while True:
    height = get_int("Height: ")

    if height > 0 and height < 9:
        break

# build pyramid
for i in range(0, height, 1):
    print(" " * (height - 1 - i), end="")
    for j in range(0, i + 1, 1):
        print("#", end="")
    print()