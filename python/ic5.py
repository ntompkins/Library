# nathan_tompkins_ic5.py
# Nathan Tompkins
# 10.5.15

def milesToKm():
    quantity = float(input("Enter your miles: "))
    
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity / 1.6
        print(new_quantity,"\n")
    
def FahToCel():
    quantity = float(input("Enter your degrees in Fahrenheit: "))
    
    if quantity > 1000:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = (quantity - 32)*(5/9)
        print(new_quantity,"\n")
        
def GalToLit():
    quantity = float(input("Enter your gallons: "))
    
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else: 
        new_quantity = quantity * 3.785
        print(new_quantity,"\n")
    
def PoundsToKg():
    quantity = float(input("Enter your pounds: "))
    
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity * .45
        print(new_quantity,"\n")

def InchesToCm():
    quantity = float(input("Enter your inches: "))
    
    if quantity < 0:
        print("I\'m sorry, that's not a valid input.")
    else:
        new_quantity = quantity * 2.54
        print(new_quantity,"\n")

def main():
    print("Unit Converter")
    quantity = float(input("What is your quantity:")
    milesToKm(quantity)
    FahToCel()
    GalToLit()
    PoundsToKg()
    InchesToCm()
    print("End")
    
main()