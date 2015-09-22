# nathan_tompkins_lab3.py
# name: Nathan Tompkins
# date: 9.16.15

# GRADE AVERAGER
# This program takes the input of multiple students' grades
# and converts them to a letter grade and average

# Amount of students
students = int(input("GRADE AVERAGER\nNumber of students: "))
print("Please enter a numerical grade for each assignment. Enter '-1' when you have finished.")

# For each student, ask grade for each assignment as an integer
for i in range(students):
    
    # Set our variables to usable values
    grade = 1
    total_grade = 0
    average = 0
    assignments = 0
    letter_score = '*null*'
    
    # When user enters -1, the while loop breaks. 
    while grade > 0:
        if grade == 1:
            grade = 0
        # Prompt user for grade 
        grade = float(input("Grade: ")) 
       
        if grade >= 0:
            # Add all of our grades into one big one
            total_grade += grade
            # Keep a tally of the number of assignments by adding 1 everytime we loop
            assignments += 1 
        
    # Calculate the average for the student
    average = total_grade / assignments 
    
    # Letter grade calculator
    if average >= 90:
        letter_score = 'A'
    elif average >= 80:
        letter_score = 'B'
    elif average >= 70:
        letter_score = 'C'
    elif average >= 60:
        letter_score = 'D'
    else:
        letter_score = 'F'
    
    print("This student earned a grade of",letter_score,"with the score:",format(average,'.0f'))