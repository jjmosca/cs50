from sys import exit
from cs50 import get_int


def main():
    # Ask user for pyramid height (must be from 1 to 8)
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break
    pyramid(height)


def space(l):  # Function that prints n number of spaces
    print(" " * l, end="")
    

def hashes(i):  # Function that prints # pyramid of height n
    for k in range(i + 1):
        print("#", end="")


def pyramid(n):
    for i in range(n):  # Iterate through each row
        for j in range(n - 1 - i):  # Spaces to create right-aligned pyramid
            space(1)
        hashes(i)   # Right-aligned pyramid
        space(2)  # Gap of 2 spaces
        hashes(i)   # Left-aligned pyramid
        print()


main()