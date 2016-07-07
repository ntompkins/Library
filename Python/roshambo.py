# ROSHAMBO

import random
print("ROSHAMBO!")

def player():
    valid = False
    while valid == False:
        user = str(input("\nrock, paper, or scissors: ")).lower()
        if user == "rock":
            return user
        elif user == "paper":
            return user
        elif user == "scissors":
            return user
        else:
            print("Whoops! Please make sure your choice is valid.")

def rock(user):
    print("Computer chose rock.")

    if user == "paper":
        print("You win!")
        play_again()
    elif user == "scissors":
        print("You lose!")
        play_again()
    else:
        print("It's a tie!")

def paper(user):
    print("Computer chose paper.")
    
    if user == "scissors":
        print("You win!")
        play_again()
    elif user == "rock":
        print("You lose!")
        play_again()
    else:
        print("It's a tie!")

def scissors(user):
    print("Computer chose scissors.")
    
    if user == "rock":
        print("You win!")
        play_again()
    elif user == "paper":
        print("You lose!")
        play_again()
    else:
        print("It's a tie!")

def play_again():
    valid = False
    while valid == False:
        repeat = str(input("\nPlay again? (y/n) ")).lower()
        if repeat == "y":
            end = False
            valid = True
        elif repeat == "n":
            quit()
        else:
            print("Error, please enter either \"y\" or \"n\"")

def main():
    end = False
    while end == False:
        randy = random.randint(1, 3)
        if randy == 1:      # Rock
            rock(player())
        elif randy == 2:    # paper
            paper(player())
        elif randy == 3:    # Scissors
            scissors(player())
        else:
            print("Something went horribly wrong!")
main()
