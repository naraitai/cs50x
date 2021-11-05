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