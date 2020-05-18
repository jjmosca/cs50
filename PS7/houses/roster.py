import csv
from sys import argv
import re
import cs50

# Exit if cmd line argument is not equal to 2
if len(argv) != 2:
    print("Usage: python roster.py Gryffindor")
    exit()

else:

    house = argv[1]

    # Import database
    db = cs50.SQL("sqlite:///students.db")
    
    # Select statement
    query = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", house)

    # Iterate through each row from query and print names under specified house
    for row in query:
        middle = row["middle"]
        if middle == None:
            print(row["first"], row["last"], end='')
        else:
            print(row["first"], row["middle"], row["last"], end='')
        print(", born", row["birth"])
        