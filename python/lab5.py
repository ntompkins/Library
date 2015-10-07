# nathan_tompkins_lab5.py 
# Number Guesser
# Nathan Tompkins | 10.7.15

import random

def main():
    # Set random number
    rand_number = random.randint(1, 100)
    
    # Set variables
    guess = rand_number - 1
    guess_count = 0
    # While loop that checks input
    print("\nHere we go...")
    while guess != rand_number:
        # Prompt for guess
        guess = float(input("Enter your guess: "))
        # Add guess count to total
        guess_count += 1
        # Create conditional statement for subject verb agreement (personal choice)
        grammar = ""
        if guess_count == 1:
            grammar = "try"
        else:
            grammar = "tries"
        # hints
        if guess != rand_number:
            if guess > rand_number and guess < (rand_number + 5):
                print("Incorrect, but you're getting closer. Go lower.")
            elif guess < rand_number and guess > (rand_number - 5):
                print("Incorrect, but you're getting closer. Go higher.")
            else:
                print("Incorrect. Try again!\n")
    # print results
    print("Congratulations! You guessed the number in",guess_count,grammar)

# While loop to continue playing"
print("Number Guesser\nThis program will generate a random\nnumber between 1 and 100. It's your job to guess it.")
query = "yes"
while query != "no":
    # Program title and instructions
    main()
    # Prompt for try again
    query = str(input("\nWould you like to try again? ( yes or no ): "))
    if query == "yes":
        main()
        
print("\n-END-")
quit()
    
    