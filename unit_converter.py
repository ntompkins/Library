# unit_converter.py
# name: Nathan Tompkins
# date: 9.5.15
# This program converts between:
#  * kilometres and miles
#  * fahrenheit and celsius
#  * gallons and litres
#  * pounds and kilograms
#  * inches and centimetres

# Functions used in this program are:
# print, input, str, lower, float, if, else
 
# 1)  Welcome the user and declare what this program does.
# 2)  Questions the user on the quantity and then which unit they would like to convert. I explicitly state acceptable forms.

# Store our amount in a variable titled [quantity] and our units in a variable titled [unit].
quantity = float(input("This is a unit converter.\nValid units are km, mi, F, C, gal, L, lb, kg, in, and cm.\nTo begin, what is the quantity of your unit? [numbers only]\n"))
unit = input("Next, what type of unit are you converting? [letters only]\n")

# 3) Convert [unit] to a lowercase string to define the type and simplify results.
unit = str(unit).lower()

# 4)  Begin testing [unit] against valid options, starting with km.
if unit == 'km':
    # if [unit] equals 'km' convert it to miles with the following calculations.
    # all nested statements follow this pattern
    new_quantity = quantity * 1.6
    new_unit = 'miles'
    # print users input and the converted unit as well
    print(quantity,unit,'equals',new_quantity,new_unit)
else:
    if unit == 'mi':
        new_quantity = quantity / 1.6
        new_unit = 'kilometres'
        print(quantity,unit,'equals',new_quantity,new_unit)
    else:
        if unit == 'f':
            new_quantity = (quantity - 32) * (5/9)
            new_unit = 'celsius'
            print(quantity,unit,'equals',new_quantity,new_unit)
        else:
            if unit == 'c':
                new_quantity = (quantity * (9/5)) + 32
                new_unit = 'fahrenheit'
                print(quantity,unit,'equals',new_quantity,new_unit)
            else:
                if unit == 'gal':
                    new_quantity = quantity * 3.785
                    new_unit = 'litres'
                    print(quantity,unit,'equals',new_quantity,new_unit)
                else:
                    if unit == 'l':
                        new_quantity = quantity / 3.785
                        new_unit = 'gallons'
                        print(quantity,unit,'equals',new_quantity,new_unit)
                    else: 
                        if unit == 'lb':
                            new_quantity = quantity * .45
                            new_unit = 'kilograms'
                            print(quantity,unit,'equals',new_quantity,new_unit)
                        else:
                            if unit == 'kg':
                                new_quantity = quantity / .45
                                new_unit = 'pounds'
                                print(quantity,unit,'equals',new_quantity,new_unit)
                            else: 
                                if unit == 'in':
                                    new_quantity = quantity * 2.54
                                    new_unit = 'centimetres'
                                    print(quantity,unit,'equals',new_quantity,new_unit)
                                else:
                                    if unit == 'cm':
                                        new_quantity = quantity / 2.54
                                        new_unit = 'inches'
                                        print(quantity,unit,'equals',new_quantity,new_unit)
                                    else:
                                        # if [unit] does not equal a valid option, we alert the user of their error.
                                        print("I'm sorry, that's not a valid unit.\nPlease check the valid units and try again.")
