import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database.csv sequences.txt")

    # Initiate a database from the csv file wherein each row is stored as a dict
    # database[0]['name'] and so on
    database = []
    # Initiate a subsequences list to save all the subsequences from the csv file
    subsequences = []
    # Read's database file into a variable
    with open(sys.argv[1], newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        subsequences = reader.fieldnames[1:]
        for row in reader:
            database.append(row)

    # Read's  DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        sequence = file.read()

    # stores the count of all subsequences in a variable for ease of use
    sqnce_count = len(subsequences)
    matches = []
    # Find's the longest match of each STR in DNA sequence and add's the result to the list
    for i in range(sqnce_count):
        matches.append((longest_match(sequence, subsequences[i])))

    # Check's the database for matching profiles
    # if the match count equates to the total STR_count there's a definitive match
    # print's the name and exits or print's out that thhere's no match at all
    for i in range(len(database)):
        count = 0       # sets count to zero for each person in the database
        for j in range(sqnce_count):
            if str(matches[j]) == (database[i][subsequences[j]]):
                count += 1
                if count == sqnce_count:
                    sys.exit(database[i]['name'])

    else:
        print("no match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
