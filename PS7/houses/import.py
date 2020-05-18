import csv
from sys import argv
import re
import cs50

# Exit if cmd line argument is not equal to 2
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit()

else:
    # Second cmd line argument must be a csv file
    if re.search("\.(csv)$", argv[1]):

        # Import database
        db = cs50.SQL("sqlite:///students.db")

        # Open csv file
        with open(argv[1], "r") as characters:
            reader = csv.DictReader(characters)

            # Iterate through each row
            for row in reader:

                # Parse names into first middle last
                name = row["name"].split()
                first = name[0]
                if len(name) == 3:
                    middle = name[1]
                    last = name[2]
                elif len(name) == 2:
                    middle = None  # If no middle name set it to NULL
                    last = name[1]
                else:
                    continue

                house = row["house"]
                birth = row["birth"]

                # Insert values into students table as columns
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                           first, middle, last, house, birth)
    else:
        print("Usage: python import.py characters.csv")
        exit()
