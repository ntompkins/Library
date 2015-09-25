# nathan_tompkins_lab2.py
# name: Nathan Tompkins
# date: 9.10.15

#        UNIT CONVERTER
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

#   2) Validating statements
if quantity < 0 and (unit != "c" and unit != "f"):      # I. [quantity] cannot be negative while [unit] is neither "c" or "f"
    print("Error, please enter a positive number or try a different unit.")
elif quantity > 1000 and (unit == "c" or unit == "f"):  # II. "f" and "c" cannot be greater than 1000.
    print("Error, please enter a number that's smaller than 1000.")
#   3)  Begin testing [unit] against valid options
elif unit == "km":
    new_quantity = quantity * 1.6
    new_unit = "miles"                  
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "mi":
    new_quantity = quantity / 1.6
    new_unit = "kilometers"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "f":
    new_quantity = (quantity - 32) * (5/9)
    new_unit = "celsius"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "c":
    new_quantity = (quantity * (9/5)) + 32
    new_unit = "fahrenheit"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "gal":
    new_quantity = quantity * 3.785
    new_unit = "liters"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "l":
    new_quantity = quantity / 3.785
    new_unit = "gallons"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "lb":
    new_quantity = quantity * .45
    new_unit = "kilograms"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "kg":
    new_quantity = quantity / .45
    new_unit = "pounds"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "in":
    new_quantity = quantity * 2.54
    new_unit = "centimeters"
    print(quantity,unit,"=",new_quantity,new_unit)
elif unit == "cm":
    new_quantity = quantity / 2.54
    new_unit = "inches"
    print(quantity,unit,"=",new_quantity,new_unit)
else: 
    print("Error, that's not a valid unit.\nPlease check the valid units and try again.")   # III. If [unit] does not equal a valid option, we alert the user of their error.