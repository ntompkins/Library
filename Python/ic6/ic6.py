# Nathan Tompkins / 10.12.15
# nathan_tompkins_ic6.py

# This program allows the user to choose various
# geometry calculations from a menu. This program
# imports the circle and rectangle modules.
import circle
import rectangle
import triangle

# Constants for the menu choices
AREA_CIRCLE_CHOICE = 1
CIRCUMFERENCE_CHOICE = 2
AREA_RECTANGLE_CHOICE = 3
PERIMETER_RECTANGLE_CHOICE = 4
AREA_TRIANGLE_CHOICE = 5
PERIMETER_TRIANGLE_CHOICE = 6
QUIT_CHOICE = 7

# The main function.
def main():
    # The choice variable controls the loop
    # and holds the user's menu choice.
    choice = 0

    while choice != QUIT_CHOICE:
        # display the menu.
        display_menu()

        # Get the user's choice.
        choice = int(input('Enter your choice: '))

        # Perform the selected action.
        if choice == AREA_CIRCLE_CHOICE:
            radius = float(input("Enter the circle's radius: "))
            print('The area is', circle.area(radius))
        elif choice == CIRCUMFERENCE_CHOICE:
            radius = float(input("Enter the circle's radius: "))
            print('The circumference is', \
                  circle.circumference(radius))
        elif choice == AREA_RECTANGLE_CHOICE:
            width = float(input("Enter the rectangle's width: "))
            length = float(input("Enter the rectangle's length: "))
            print('The area is', rectangle.area(width, length))
        elif choice == PERIMETER_RECTANGLE_CHOICE:
            width = float(input("Enter the rectangle's width: "))
            length = float(input("Enter the rectangle's length: "))
            print('The perimeter is', \
                  rectangle.perimeter(width, length))
        elif choice == AREA_TRIANGLE_CHOICE:
            base = float(input("Enter the triangle's base: "))
            height = float(input("Enter the triangle's height: "))
            print("The area is", \
                triangle.area(base, height))
        elif choice == PERIMETER_TRIANGLE_CHOICE:
            side1 = float(input("Enter the first side's length: "))
            side2 = float(input("Enter the second side's length: "))
            side3 = float(input("Enter the third side's length: "))
            print('The perimeter is', \
                triangle.perimeter(side1, side2, side3))
        elif choice == QUIT_CHOICE:
            print('Exiting the program...')
        else:
            print('Error: invalid selection.')
    
# The display_menu function displays a menu.
def display_menu():
    print('        MENU')
    print('1) Area of a circle')
    print('2) Circumference of a circle')
    print('3) Area of a rectangle')
    print('4) Perimeter of a rectangle')
    print('5) Area of a triangle')
    print('6) Perimeter of a triangle')
    print('7) Quit')

# Call the main function.
main()
