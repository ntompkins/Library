import os
import student
import student_db

# nathan_tompkins_lab10.py
# Nathan Tompkins | 12.1.15
# Student Database

#   Using the Student class you created for In-Class Exercise 10, you will write a menu driven
#   program that performs the following tasks:
#   1. Look up and display a student GPA
#   2. Add a new student to the class
#   3. Change the final grade of a student
#   4. Print the data of all the students (1 line per student) that includes Student ID, Name,
#   GPA, and Final Grade.
#   5. Quit the program


def main():
    
    print("-STUDENT DATABASE-")                 # Program name
    
    QUIT = False
    while QUIT == False:                        # Generate loop
        
        menu()                                  # Call menu function
        quitmenu()                              # Call quit menu function

def menu():
    
    VALID = False
    while VALID == False:                       # Generate loop
        
        print("\nMENU\n1) View Student Information\n2) Edit Student Information")
        
        choice = str(input("> "))               # Get input
        
        
        if choice == "1":                       # View Students or
            roster()
            VALID = True
            
        elif choice == "2":                     # Edit Students or
            print("Yep yep")
            VALID = True
            
        else:                                   # Error loop
            print("Try again.")
        
def roster():
    
    VALID = False
    while VALID == False:
        
        print("\nVIEW STUDENTS\n-------------") # Display inner menu
        print("1) View All Students\n2) Choose Student")
        
        choice = str(input("> "))               # Get input
        
        if choice == "1":                       # View all students or
            print()
            for each_student in student_list:           # Print out each student's name
                print(each_student,", ",student_list[each_student],sep="")
            VALID = True
        
        elif choice == "2":                     # Print individual student's information or
            print("Which student would you like to view:\n")
            
            for each_student in student_list:           # List students by first name
                print(each_student)
            
            selec = str(input("> ")).capitalize()
            if selec not in student_list:               # Validate that choice is a student
                print("Try again.\n")
            else:
                print("You chose",selec)                # Print out student name, GPA
                VALID = True
        else:
            print("Try again\n")                # Error loop
        
        
            

def quitmenu():
    
    val = False
    while val == False:
        
        menu = str(input("Quit program? (y/n) "))   # Get input
        if menu == "y":
            print("Program closing...")             # Close program or
            quit()
        elif menu == "n":                           # Exit loop and rerun program or
            val = True
        else:                                       # Error loop
            print("Try again.")                     

# Call main function
main()  