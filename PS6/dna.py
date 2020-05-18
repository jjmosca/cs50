from sys import argv
import csv
import re


# Exit if user does not have 3 arguments
if len(argv) != 3:
    print("Usage: python data.py database.csv sequence.txt")
    exit()

else:
    # Checks if 2nd argument is csv file and 3rd is txt file
    if re.search("\.(csv)$", argv[1]) and re.search("\.(txt)$", argv[2]):

        # Open both files and read into memory
        with open(argv[1], 'r') as csvfile, open(argv[2], 'r') as txtfile:
            data = csv.DictReader(csvfile)
            sequence = txtfile.read()

            # Initiliaze dicitionary of max consecutive repeats
            dna_str = {}

            # Counts maximum number of consecutive repeats of STR
            for i in range(1, len(data.fieldnames)):
                # Finds all matches of database header (STRs) in dna sequence
                match = re.findall(rf"((?:{data.fieldnames[i]})+)", sequence)
                if match:
                    x = len(max(match)) // len(data.fieldnames[i])  # Computes for max repeats
                    dna_str.update({f'{data.fieldnames[i]}': x})  # Append to dictionary
            
            # Iterate through each row in database
            for row in data:
                name = row["name"]  # Stores name of person in row
                match = 0
                # Iterate through each key in dictionary dna_str and find exact match in database
                for dna in dna_str:
                    if dna_str[dna] == int(row[dna]):
                        match += 1
                if match == (len(data.fieldnames) - 1):
                    print(name)
                    exit()
                    
            print("No match")

    else:
        print("Usage: python data.py database.csv sequence.txt")
