# nathan_tompkins_lab1.py
# name: Nathan Tompkins
# date: 9.9.15

# This program converts between:
#  * kilometres and miles
#  * fahrenheit and celsius
#  * gallons and litres
#  * pounds and kilograms
#  * inches and centimetres

# Functions used in this program are:
# print, input, float, format

# Introduction
print("Hello! This is a unit converter.")

# Convert miles to km
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