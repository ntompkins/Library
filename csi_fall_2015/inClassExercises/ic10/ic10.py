# nathan_tompkins_ic10.py
# Nathan Tompkins | 11.23.15
# Student Database
import student
# Import individuals
import student1
import student2
import student3
import student4
import student5

def main():
# Create dictionary for all students
       
    cole = student.Student(student1.name, student1.student_id, student1.gpa, student1.final, student1.full_or_part)
    lisa = student.Student(student2.name, student2.student_id, student2.gpa, student2.final, student2.full_or_part)
    john = student.Student(student3.name, student3.student_id, student3.gpa, student3.final, student3.full_or_part)
    matt = student.Student(student4.name, student4.student_id, student4.gpa, student4.final, student4.full_or_part)
    jill = student.Student(student5.name, student5.student_id, student5.gpa, student5.final, student5.full_or_part)
    
    student_list = {
        "Cole":cole,
        "Lisa":lisa,
        "John":john,
        "Matt":matt,
        "Jill":jill
        }
 
    print("STUDENT DATABASE\n")
    end = False
    while end == False:
        
        # Begin student menu
        val = False
        while val == False:
            print("* Cole \n* Lisa \n* John \n* Matt \n* Jill")
            
            choice = str(input("Which student would you like to access: ")).strip().lower()
            if choice == "cole":
                active_profile = student_list["Cole"]
                profile_reader(active_profile)
                val = True
            elif choice == "lisa":
                active_profile = student_list["Lisa"]
                profile_reader(active_profile)
                val = True
            elif choice == "john":
                active_profile = student_list["John"]
                profile_reader(active_profile)
                val = True
            elif choice == "matt":
                active_profile = student_list["Matt"]
                profile_reader(active_profile)
                val = True
            elif choice == "jill":
                active_profile = student_list["Jill"]
                profile_reader(active_profile)
                val = True
            else:
                print("Invalid choice. Please try again.")

            quitmenu()
            
def profile_reader(active_profile):
    val = False
    while val == False:
        menu = str(input("Read or edit: ")).lower()
        if menu == "read":
            # Read file using class
            print(  "Student's Name: ",active_profile.get_name(),\
                    "\nID: ",active_profile.get_student_id(), \
                    "\nGPA: ",active_profile.get_gpa(), \
                    "\nFinal Grade: ",active_profile.get_final(), \
                    "\nPart or Full time: ",active_profile.get_full_or_part())
            print()
            val = True
            
        elif menu == "edit":
            print("You are now editing ",active_profile.get_name(),"\'s profile.",sep="")
            passthrough = False
            while passthrough == False:
                print("1) Student ID\n2) GPA\n3) Final Grade\n4) Part Time or Full Time")
                choice = str(input("Which field would you like to edit: "))
                # EDITING SEQUENCE
                
                if choice == "1":   # Student ID
                    student_id = str(input("Enter the new ID: "))
                    active_profile.set_student_id(student_id)
                    print("The new ID is",active_profile.get_student_id())
                
                elif choice == "2": # GPA
                    gpa = str(input("Enter the new GPA: "))
                    active_profile.set_gpa(gpa)
                    print("The new GPA is",active_profile.get_gpa())
                
                elif choice == "3": # Final Grade
                    final = str(input("Enter the new final grade: "))
                    active_profile.set_final(final)
                    print("The new final grade is",active_profile.get_final())
                    
                elif choice == "4": # Part or Full time
                    val = False
                    while val == False:
                        full_or_part = str(input("Enter the new student type: ")).lower()
                        if full_or_part == ("part" or "full"):
                            active_profile.set_full_or_part(full_or_part)
                            print("The new student type is",active_profile.get_full_or_part(),"time.")
                            val = True
                        else:
                            print("Error, please enter either 'part' or 'full'.")
                else:
                    print("You chose an invalid choice.")
                
                menu = str(input("Would you like to edit another field? (y/n) ")).lower()
                if menu == "y":
                    print()
                elif menu == "n":
                    print()
                    passthrough = True
                else:
                    print("Error, please try again.")
                
            
            val = True
        else:
            print("Error, invalid choice.")
            
def quitmenu():
    val = False
    while val == False:
        menu = str(input("Would you like to view another student? (y/n) "))
        if menu == "y":
            val = True
        elif menu == "n":
            print("Program closing...")
            quit()
        else:
            print("Error, invalid choice.")
main()

