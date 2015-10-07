# nathan_tompkins_ic5.py
# Nathan Tompkins | 10.5.15

def results():
    print(quantity,unit,"=",new_quantity,new_unit)
    
# Miles to Kilometers function
def milesToKm():
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity / 1.6

# Fahrenheit to Celsius function
def FahToCel():
    if quantity > 1000:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = (quantity - 32)*(5/9)

# Gallons to Liters function
def GalToLit():
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity * 3.785
        print(new_quantity,"\n")

# Pounds to Kilograms function
def PoundsToKg():
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity * .45
        print(new_quantity,"\n")

# Inches to Centimeters function
def InchesToCm():
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity * 2.54
        print(new_quantity,"\n")

# main function
def main():
    print("Unit Converter")
    global quantity
    quantity = float(input("Your quantity: "))
    
    milesToKm()
    unit = "Miles"
    new_unit = "Kilometers"
    results()
    
    FahToCel()
    GalToLit()
    PoundsToKg()
    InchesToCm()
    print("End")
main()
