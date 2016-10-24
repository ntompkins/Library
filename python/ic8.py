# nathan_tompkins_ic8.py
# Nathan Tompkins | 11.12.15

def main():
    # 1)
    choice = ("Y" and "y").lower()
    if choice == "y":
    	print("The 'y' is lowercase.")
    else:
    	print("The 'y' is capitalized.")
    
    # 2)
    # Create string
    myString = "Lorem ipsum DOLOR sit amet 231"
    
    if " " in myString:
        spaces = myString.count(" ")
    
    # 3)
    numbers = 0
    for i in myString:
        if i.isdigit():
            numbers+=1
    
    # 4)
    letters = 0
    for i in myString:
        if i.islower():
            letters+=1
    
    # 2,3,4 results
    print("There are",spaces,"spaces,",numbers,"numbers, and",letters,"lowercase letters in your string.\n")
    
    # 5)
    email = input(str("Enter an email address: "))
    if email.endswith(".com"):
    	print("Your email is a valid .com address.\n")
    else:
    	print("Your email in not a valid .com address.\n")
    
    # 6)
    tstring = "taco tuesday is a terrific tradition"
    newstring = tstring.replace("t","T")
    print(tstring,"becomes",newstring)

main()