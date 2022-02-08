"""---------------------------------
Task 7 of 8

Brief
- Python version of pset2 readability
- Compute approximate grade level needed to understand a text
- Implement the Coleman-Liau index

Expected output
     
    Text: <user input text>
    Grade <integer>
    
Distribution code
- None

None Standard Libraries
- cs50

Key concept:
- Arrays
- Algorithms
-----------------------------------"""

from cs50 import get_string

text = get_string("Text: ")

# Get number of letter in text
letters = 0
for i in text:
    if i.isalpha():
        letters += 1
        
# Get number of words in text
words = 1
for i in text:
    if i.isspace():
        words += 1

# Get number of sentences
sentences = 0
for i in text:
    if i == "." or i == "!" or i == "?":
        sentences += 1

# Calculate Coleman-Liau Index
index = round(0.0588 * (100 / words * letters) - 0.296 * (100 / words * sentences) - 15.8)

# Print grade
if index < 1:
    print("Before Grade 1")

elif index > 16:
    print("Grade 16+")
    
else:
    print(f"Grade {index}")
    