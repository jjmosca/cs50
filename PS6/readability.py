from cs50 import get_string
import re


def main():
    text = get_string("Text: ")
    
    # Computes for index from Coleman-Liau formula
    L = (count_letters(text) / count_words(text)) * 100
    S = (count_sen(text) / count_words(text)) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    
    if (index > 16):
        print("Grade 16+")
    elif (index < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {int(round(index))}")
        

# Counts number of words using split function
# Split function separates text per whitespace character
def count_words(text):
    count = 0
    for word in text.split():
        count += 1
    return count
    

# Counts number of letters in each word
def count_letters(text):
    count = 0
    # Searches for alphanumeric set of characters separated by non-alphanumeric characters
    for w in re.findall('\w+', text):
        for c in w:
            count += 1
    return count
    

# Counts number of punctuations (period, exclamation point, question mark)
def count_sen(text):
    count = 0
    for punc in re.findall(r'[.!?]', text):
        count += 1
    return count
    
    
main()