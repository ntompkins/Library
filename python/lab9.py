# nathan_tompkins_lab9.py
# Nathan Tompkins | 11.24.15
# Email Database
"""Write a program that keeps names and email addresses in a dictionary as key-value pairs.
The program should display a menu that lets the user look-up a person’s email address, add a
new name and email address, change an existing email address, and delete an existing name
and email address.
"""
def main():
    # Welcome user
    print("EMAIL DATABASE")
    menu(choice)
def menu(choice):
    choice = str(input("1) View Database\n \
                        2) Search Database\n \
                        3) Change Entry\n \
                        4) Delete Entry\n \
                        \t:"))
    return choice
main()
