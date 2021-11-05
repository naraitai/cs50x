import sys
import csv


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE.csv SEQUENCE.txt")

    # Open file and read as dictionaries into list
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        header = reader.fieldnames

        # Store rows as dictionaries
        people = 0
        for row in reader:
            database.append(row)
            people += 1

        # Cast STRs to ints
        for i in range(1, len(header), 1):
            for j in range(people):
                database[j][header[i]] = int(database[j][header[i]])

    # Open sequence file and read into list
    with open(sys.argv[2]) as file:
        reader = csv.reader(file)

        for row in reader:
            sequence = row

    # Call function on each STR and store result
    repeats = {}
    for i in range(1, len(header), 1):
        repeats[header[i]] = consecutive(sequence, header[i])

    # Check if anyone matches all STR counts
    match = ""

    # Loop through each person in database
    for i in range(0, len(database), 1):
        count = 1

        # Loop through each STR
        for j in range(1, len(header), 1):
            # Check values match
            if database[i][header[j]] == repeats[header[j]]:
                count += 1
                # Check for someone who matches all STR values and store name
                if count == len(header):
                    match = database[i]["name"]
            else:
                break

    # Display result to screen
    if match:
        print(match)
    else:
        print("No match")


def consecutive(sequence, header):
    block = len(header)
    end = len(sequence[0])

    count = 0
    maximum = 0

    # Loop through each character
    for i in range(end):

        # Reset the consecutive counter
        while count > 0:
            count -= 1
            continue

        # Check for match
        if sequence[0][i: i + block] == header:
            count += 1

            # Loop to find all matches
            while sequence[0][i - block: i] == sequence[0][i: i + block]:
                count += 1
                i += block

            # Update and store new maximum consecutive run
            if count > maximum:
                maximum = count

    return maximum


if __name__ == "__main__":
    main()
