# nathan_tompkins_lab4.py
# name: Nathan Tompkins
# date: 9.24.15

error_count = 0 # Variable that holds the user's input validity

print("UNIT CONVERTER\n")

# Miles to kilometers
while error_count < 3:
    unit = float(input("How many miles do you want to convert to kilometers? "))
    if unit > 0:
        out = format(unit * 1.6, ".3f")
        print(unit,"miles equals",out,"kilometers.")
        error_count = 3
    else:
        error_count += 1
        print("\nError. Input must be greater than 0. You have",3 - error_count,"tries left.")
error_count = 0

# Fahrenheit to celsius
while error_count < 3:
    unit = float(input("What temperature Fahrenheit do you want to convert to Celsius? "))
    if unit <= 1000:
        out = format((unit - 32) * (5/9),".3f")
        print(unit,"degrees Fahrenheit equals",out,"degrees Celsius.")
        error_count = 3
    else:
        error_count += 1
        print("\nError. Input must be less than 1000. You have",3 - error_count,"tries left.")
error_count = 0

# Gallons to liters
while error_count < 3:
    unit = float(input("How many gallons would you like to convert to liters? "))
    if unit > 0:
        out = format(unit * 3.785,".2f")
        print(unit,"gallons equals",out,"litres.")
        error_count = 3
    else:
        error_count += 1
        print("\nError. Input must be greater than 0. You have",3 - error_count,"tries left.")
error_count = 0

# Pounds to kilograms
while error_count < 3:
    unit = float(input("How many pounds would you like to convert to kilograms? "))
    if unit > 0:
        out = format(unit * .45,".2f")
        print(unit,"pounds equals",out,"kilograms.")
        error_count = 3
    else:
        error_count += 1
        print("\nError. Input must be greater than 0. You have",3 - error_count,"tries left.")
error_count = 0

# Inches to centimeters
while error_count < 3:
    unit = float(input("How many inches would you like to convert to centimeters? "))
    if unit > 0:
        out = format(unit * 2.54,".2f")
        print(unit,"inches is equal to",out,"centimeters.")
        error_count = 3
    else:
        error_count += 1
        print("\nError. Input must be greater than 0. You have",3 - error_count,"tries left.")
error_count = 0

print("\nEND")