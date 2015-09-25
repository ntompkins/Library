# nathan_tompkins_IC4.py
# name: Nathan Tompkins
# date: 9.21.15

# This program draws a triangle from the user's
# base to a tip of 1 asterisk.

# Request triangle base
base = int(input("What is the base of your triangle? "))
# Conditional error for negative bases
if base < 1:
    print("Error. Please enter a value for the base that is greater than 1.")
else:
    # Create blank line for triangle to be drawn
    print("\n")
    # For each integer in the variable base, we draw a line of asterisks
    for r in range(base):
        # Subtract one value of r from the base to shorten the line
        for c in range(base-r):
            # Print the asterisk and end the line
            print("*",end="")
        # Print the completed triangle
        print()