from cs50 import get_string
import re


def main():
    card = get_string("Number: ")

    # Verify if card result of checksum ends in 0
    if checksum(card) % 10 == 0:

        # Verify if card has 15 digits and starts with 34 or 37
        if re.search("^3(4|7)[0-9]{13}", card):
            print("AMEX")

        # Verify if card has 16 digits and starts with 51 to 55
        elif re.search("^5(1|2|3|4|5)[0-9]{14}", card):
            print("MASTERCARD")

        # Verify if card has 13 or 16 digits and starts with 4
        elif (len(card) == 13 or len(card) == 16) and re.search("^4", card):
            print("VISA")

    # Print INVALID if none of the conditions above were met
        else:
            print("INVALID")
    else:
        print("INVALID")


def double(n):
    return n * 2


# Luhn's Algorithm
def checksum(card):
    sum_dige = sum_digo = 0

    # Iterate through every other digit starting with 2nd-to-last digit
    for digite in map(int, card[-2::-2]):

        # Multiply that digit by 2 then add every digit in product
        for prod_dig in str(double(digite)):
            sum_dige += int(prod_dig)

    # Add every digit that weren’t multiplied by 2.
    for digito in map(int, card[-1::-2]):
        sum_digo += digito

    # Add both sums
    return sum_dige + sum_digo


main()