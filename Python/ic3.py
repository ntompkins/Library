# nathan_tompkins_IC3.py
# name: Nathan Tompkins
# date: 9.14.15

# program title and description
print("Budget Analysis")
# input user's budget
budget = float(input("Please enter your current budget: "))

# input expenses, loop this, break loop if expense equals "done"
expense = 1
total_expense = 0

print("Enter '0' or a negative number to see your total expenses.\n")
while expense > 0:
    # To remove the value of 1 that we assigned
    if expense == 1:
        expense = expense - 1
    total_expense = expense + total_expense
    expense = 0
    expense = float(input("Enter an expense to add it to your total: "))

# To offset the subtraction
# print total expenses and whether or not the user is over budget
print("Your total expense is",total_expense)

if total_expense > budget:
    print("You are over budget by",total_expense - budget)
elif total_expense == budget:
    print("You have met but not exceeded your budget.")
else:
    print("You are under budget by",budget - total_expense)