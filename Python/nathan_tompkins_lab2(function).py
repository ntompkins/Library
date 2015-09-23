# nathan_tompkins_lab2.py
# name: Nathan Tompkins
# date: 9.10.15

# UNIT CONVERTER
# This program converts between:
#  * kilometers and miles
#  * fahrenheit and celsius
#  * gallons and liters
#  * pounds and kilograms
#  * inches and centimeters

# Functions used in this program are:
# print, input, str, lower, float, if, elif, else

#   1)  Store our amount in a variable titled [quantity] and our units in a variable titled [unit] {explicitly state acceptable forms}
quantity = float(input("UNIT CONVERTER\nPossible conversions are [km : mi] [f : c] [gal : l] [lb : kg] [in : cm]\nEnter your quantity (digits only): ")) 

# Prompt for unit. convert to string, convert to lowercase.
unit = str(input("Enter your unit: ")).lower()

#   2) Create function called 'results()' that will deliver our results in a constant format
def results():
    print(quantity,unit,"=",new_quantity,new_unit)

#   3) Validating statements
if quantity < 0 and (unit != "c" and unit != "f"):      # I. [quantity] cannot be negative while [unit] is neither "c" or "f"
    print("Error, please enter a positive number or try a different unit.")
elif quantity > 1000 and (unit == "c" or unit == "f"):  # II. "f" and "c" cannot be greater than 1000.
    print("Error, please enter a number that's smaller than 1000.")
#   4)  Begin testing [unit] against valid options
elif unit == "km":
    new_quantity = quantity * 1.6
    new_unit = "miles"                  
    results()
elif unit == "mi":
    new_quantity = quantity / 1.6
    new_unit = "kilometers"
    results()
elif unit == "f":
    new_quantity = (quantity - 32) * (5/9)
    new_unit = "celsius"
    results()
elif unit == "c":
    new_quantity = (quantity * (9/5)) + 32
    new_unit = "fahrenheit"
    results()
elif unit == "gal":
    new_quantity = quantity * 3.785
    new_unit = "liters"
    results()
elif unit == "l":
    new_quantity = quantity / 3.785
    new_unit = "gallons"
    results()
elif unit == "lb":
    new_quantity = quantity * .45
    new_unit = "kilograms"
    results()
elif unit == "kg":
    new_quantity = quantity / .45
    new_unit = "pounds"
    results()
elif unit == "in":
    new_quantity = quantity * 2.54
    new_unit = "centimeters"
    results()
elif unit == "cm":
    new_quantity = quantity / 2.54
    new_unit = "inches"
    results()
else: 
    print("Error, that's not a valid unit.\nPlease check the valid units and try again.")   # III. If [unit] does not equal a valid option, we alert the user of their error.