# Reference Angle Finder / Trig Function Calculator
# Made by Nathan Tompkins | http://github.com/ntompkins

# Import trig functions from the math library
import math

print("Reference Angle Finder")
print("Valid functions are sin, sine, cos, cosine, tan, and tangent.\nType \'quit\' to exit.")

# Define function
def find_all():
    
    # Define variables:
    org_angle = 0
    correction = "false"
    times_corrected = 0
    method = ""
    q = "0"
    prime = 0

    # Loops until input is valid
    valid = "false"
    while valid != "true":

        # Initial angle
        angle = float(input("Angle in degrees: "))

        # Allows for larger or negative angles
        if angle > 360 or angle < 0:
            print("\nYour angle",angle,"is outside the valid range. Let me help you out:")
            org_angle = angle
            correction = "true"
            times_corrected = 0

        # Brings angle into range
        while angle > 360:
            angle -= 360.0
            times_corrected += 1
            method = "subtraction"
        while angle < 0:
            angle += 360.0
            times_corrected += 1
            method = "addition"

        # Tells the user what I did to help them
        if correction == "true" and method == "subtraction":
            print("I took your angle of",org_angle,"and subtracted 360",times_corrected,"times to bring it down to a usable value of",format(angle,".2f"),"\n")
        if correction == "true" and method == "addition":
            print("I took your angle of",org_angle,"and added 360",times_corrected,"times to bring it up to a usable value of",format(angle,".2f"),"\n")

        # Create trig calculator
        trig_result = 0
        precision = input("How precise do you want your answer? ")

        # If user enters a blank line, we set the default precision to 5
        if precision != int:
            print("\nNo precision set. Default is 5.")
            precision = 5

        if trig_func == "sin":
            trig_result = round(math.sin(angle),precision)
            print("\nThe",trig_func,"of",angle,"is",trig_result)
        elif trig_func == "cos":
            trig_result = round(math.cos(angle),precision)
            print("\nThe",trig_func,"of",angle,"is",trig_result)
        elif trig_func == "tan":
            trig_result = round(math.tan(angle),precision)
            print("\nThe",trig_func,"of",angle,"is",trig_result)
        else:
            print("Something went terribly wrong.")

        # Determine angle location
        if angle >= 0 and angle <= 90:
            valid = "true"
            q = "1"
            quadrant = "You\'re in the first quadrant: Q = 1"
            print(quadrant)

        elif angle > 90 and angle <= 180:
            valid = "true"
            q = "2"
            quadrant = "You\'re in the second quadrant: Q = 2"
            print(quadrant)

        elif angle > 180 and angle <= 270:
            valid = "true"
            q = "3"
            quadrant = "You\'re in the third quadrant: Q = 3"
            print(quadrant)

        elif angle > 270 and angle <= 360:
            valid = "true"
            q = "4"
            quadrant = "You\'re in the fourth quadrant: Q = 4"
            print(quadrant)

        else:
            print("That's not a valid angle, please try again. Enter your angle in digits.")

        # Reference angle function
        if q == "1":
            print("Your reference angle is",round(angle,precision))
        elif q == "2":
            prime == 180 - angle
            print("Your reference angle is",round(prime,precision))
        elif q == "3":
            prime == angle - 180
            print("Your reference angle is",round(prime,precision))
        elif q == "4":
            prime == 360 - angle
            print("Your reference angle is",round(prime,precision))
        else:
            print("Something went terribly wrong.")

error_count = 0
while error_count < 3:
    trig_func = str(input("\nFunction: ")).lower()

    if trig_func == "quit":
        quit()
    # Sine
    if trig_func == "sine":
        trig_func = "sin"
        find_all()
    elif trig_func == "sin":
        find_all()

    # Cosine
    elif trig_func == "cosine":
        trig_func = "cos"
        find_all()
    elif trig_func == "cos":
        find_all()

    # Tangent
    elif trig_func == "tangent":
        trig_func = "tan"
        find_all()
    elif trig_func == "tan":
        find_all()

    else:
        error_count += 1
        print("Error, please enter a valid function: sine, cosine, or tangent. You have",3 - error_count,"attempt(s) left.")

print("\nEnd.")
