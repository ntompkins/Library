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

mi = float(input("How many miles do you want to convert?\n"))
km = format(mi * 1.6, ".3f")
print(mi,"miles is equal to",km,"kilometers.")

# Fahrenheit to celsius
f = float(input("What temperature Fahrenheit to you want to convert to Celsius?\n"))
c = format((f - 32) * (5/9),".3f")
print(f,"degrees Fahrenheit equals",c,"degrees Celsius.")

# Gallons to liters
gal = float(input("How many gallons would you like to convert to liters?\n"))
l = format(gal * 3.785,".2f")
print(gal,"gallons equals",l,"litres.")

# Pounds to kilograms
lb = float(input("How many pounds would you like to convert to kilograms?\n"))
kg = format(lb * .45,".2f")
print(lb,"pounds equals",kg,"kilograms.")

# Inches to centimeters
inch = float(input("How many inches would you like to convert to centimeters?\n"))
cm = format(inch * 2.54,".2f")
print(inch,"inches is equal to",cm,"centimeters.")
 
print("Error, that's not a valid unit.\nPlease check the valid units and try again.")   # III. If [unit] does not equal a valid option, we alert the user of their error.