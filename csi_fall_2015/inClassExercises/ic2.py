# nathan_tompkins_IC2.py
# name: Nathan Tompkins
# date: 9.9.15

# Functions used in this program are:
# print, float, input, if, elif, else

# Introduction
print("This program will determine your age group.\n")

# Prompt user for age:
age = float(input("Your age: "))

# Determine whether user is:

#Error return
if age <= 0:
     print("I'm sorry, that's an invalid age. Please use a positive number and try again.")
# Infant
elif age <= 1:
    print("\nYou are an infant! However, you have great computer skills.")
# Child
elif age > 1 and age < 13:
    print("\nYou're a child! Enjoy it while it lasts.")
# Teenager
elif age > 13 and age < 20:
    print("\nYou're a teenager! Stay in school!")
# Adult
else:
    print("\nYou're an adult! Enjoy your golden years.")