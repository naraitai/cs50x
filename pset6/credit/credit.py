"""---------------------------------
Task 6 of 8

Brief
- Python version of pset1 credit.c
- Implement Luhn's algorithm
- Validate a user input credit card number
- Return whether American Express / MasterCard / Visa or Invalid

Expected output
     
    Number: 378282246310005
    AMEX
    
Distribution code
- None

None Standard Libraries
- cs50

Key concept:
- Floating point values
- Algorithms
-----------------------------------"""

from cs50 import get_int

# Prompt user until number input
while True:
    number = get_int("Number: ")
    if number > 0:
        break

# Find length of number
length = len(str(number))

# Set check sum
check_sum = 0

# Loop to find check sum
tmp = number
for i in range(1, length + 1, 1):
    
    # Find every other digits starting from second to last digit and multiply by two
    if i % 2 == 0:
        digit = int((tmp % 10)) * 2
        tmp /= 10
        
        # Add each digit of sums with multiple digits (after multiplied by two)
        if digit > 9:
            check_sum += digit % 10
            digit /= 10
            check_sum += int(digit) % 10
        else:
            check_sum += digit
    
    # Simply add every other digit form the last to the check sum
    else:
        check_sum += int(tmp % 10)
        tmp /= 10
        
# Find first two digits of user input number
tmp = number
while tmp >= 100:
    tmp /= 10
tmp = int(tmp)

# Determine if check sum is valid and which company card number is associated with
if check_sum % 10 == 0:
    
    # Amex check
    if (tmp == 34 or tmp == 37) and (length == 15):
        print("AMEX")
    
    # Mastercard check    
    elif (tmp > 50 and tmp < 56) and (length == 16):
        print("MASTERCARD")
    
    # Visa check
    elif (tmp > 39 and tmp < 50) and (length == 13 or length == 16):
        print("VISA")
    
    # If all other checks failed must be number is invalid
    else:
        print("INVALID")
else:
    print("INVALID")