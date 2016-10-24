# Blackjack, or Twenty One
# ----------- ----------
# Created by Nathan Tompkins
# Source code and more available at https://github.com/ntompkins/PyCards/
import random

def main():
    menu()
    handle()
    
def menu():
    print(" ____  _            _     _            _\n" \
    "| __ )| | __ _  ___| | __(_) __ _  ___| | __\n" \
    "|  _ \| |/ _` |/ __| |/ /| |/ _` |/ __| |/ /\n" \
    "| |_) | | (_| | (__|   < | | (_| | (__|   <\n" \
    "|____/|_|\__,_|\___|_|\__/ |\__,_|\___|_|\_\ \n"\
    "\t\t\t|__/\n")
    # Menu
    fin = False
    while fin == False:
        numberOfPlayers = str(input("Enter the number of players (max 4): "))
        try:
            numberOfPlayers = int(numberOfPlayers)
            if numberOfPlayers > 4:
                print("Too many players, 4 is the max.")
            elif numberOfPlayers < 1:
                print("Oh, please. There must be at least 1 player.")
            else:
                return numberOfPlayers
        except:
            print("Error, only enter in digits. 1, 2, 3, or 4.\n")

def handle():
    # Create deck of cards, air-cushion finish if possible
    newDeck = {                 # Spades
        1:"Ace of Spades",
        2:"Two of Spades",
        3:"Three of Spades",
        4:"Four of Spades",
        5:"Five of Spades",
        6:"Six of Spades",
        7:"Seven of Spades",
        8:"Eight of Spades",
        9:"Nine of Spades",
        10:"Ten of Spades",
        11:"Jack of Spades",
        12:"Queen of Spades",
        13:"King of Spades",    # Diamonds
        14:"Ace of Diamonds",
        15:"Two of Diamonds",
        16:"Three of Diamonds",
        17:"Four of Diamonds",
        18:"Five of Diamonds",
        19:"Six of Diamonds",
        20:"Seven of Diamonds",
        21:"Eight of Diamonds",
        22:"Nine of Diamonds",
        23:"Ten of Diamonds",
        24:"Jack of Diamonds",
        25:"Queen of Diamonds",
        26:"King of Diamonds",  # Clubs
        27:"Ace of Clubs",
        28:"Two of Clubs",
        29:"Three of Clubs",
        30:"Four of Clubs",
        31:"Five of Clubs",
        32:"Six of Clubs",
        33:"Seven of Clubs",
        34:"Eight of Clubs",
        35:"Nine of Clubs",
        36:"Ten of Clubs",
        37:"Jack of Clubs",
        38:"Queen of Clubs",
        39:"King of Clubs",     # Hearts
        40:"Ace of Hearts",
        41:"Two of Hearts",
        42:"Three of Hearts",
        43:"Four of Hearts",
        44:"Five of Hearts",
        45:"Six of Hearts",
        46:"Seven of Hearts",
        47:"Eight of Hearts",
        48:"Nine of Hearts",
        49:"Ten of Hearts",
        50:"Jack of Hearts",
        51:"Queen of Hearts",
        52:"King of Hearts"
    }

    # Create a copy of newDeck to change
    deck = newDeck.copy()
    
    # Shuffle the deck
    shuffled = []
    for eachCard in deck:
        thisCard = random.randrange(len(deck))
        shuffled.append(thisCard)
    
    # Hack #1: View shuffled cards, predict the future
    #for sc in shuffled:
    #   print(sc)
    
    # Deal the cards
    deal(shuffled)

def deal(shuffled):
    
    playerHand = []
    playerChecks = 0
    playerBet = 0
    
    
    dealerHand = []
    discard = []
    
    print("Dealer: \"Welcome to Blackjack!\nPlease enter the amount of money you'd like to spend.\"")
    
    fin = False
    while fin == False:
        playerChecks = str(input("Starting money: $"))
        try:
            playerChecks = float(playerChecks)
            fin = True
        except:
            print("Dealer: \"Hey there, no funny business. Try again.\"\n")
    
    print("Dealer: \"Okay, you're starting out with",playerChecks,"dollars worth of checks.\"")
    
    
    
    
    
    
    
    
    
main()
	