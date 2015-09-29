#  nathantompkins_brownies.py
#  Name: Nathan Tompkins
#  Date: 8/31/15
#  We will determine the area of a pan and the amount of brownies it can hold

#Functions used in this program are:
# print(),input(), int(), and mathematical opperators

# 0. Welcomes the user and tells them what the program does
print("Hi there! This is a brownie counting program; it helps you determine how many brownies you can make given your current pan. Let's begin.\n")

# 1. Prompt user for the width and length of the pan in inches and convert the input to integers
width = input("What is the width of your pan in inches?\n")
width = int(width)
length = input("What is the length of your pan in inches?\n")
length = int(length)

# 2. Next we determine how large their pan actually is
area = length * width

# 3. We decide on the size of our brownies
brownies = 1 ** 2

# 4. Now we divide the area of our pan by the size of the brownies
brownie_quantity = area // brownies

# 5. Finally, we tell the brownie maker exactly how many brownies they can fit into their pan
print("You said that your pan has a width of",width,"inches, and a length of",length,"inches.\n","This means that your pan has an area of",area,"square inches and can hold",brownie_quantity,"1 inch square brownies.")