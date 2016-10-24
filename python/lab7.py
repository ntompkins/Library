# nathan_tompkins_lab7.py
# Nathan Tompkins | 11.11.15
# Driver's Test Examiner
import random
def main():
    student()
    
    # Open file with answers
    student_in = open("answers.txt","r")
    answers = []
    line = " "
   
    # As long as the line isn't blank, add the entry to the list
    while line != "":
        
        # Read the next line
        line = student_in.readline()
        cleaned = line.strip()
        
        # Add the answer to the list
        answers.append(str(cleaned))
    
    # Correct answers
    answer_key = [  "B","D","A","A","C",\
                    "A","B","A","C","D",\
                    "B","C","D","A","D",\
                    "C","C","B","D","A"]
    
    correct_questions = []
    incorrect_questions = []
    correct = 0
    incorrect = 0
    
    # Separate grades
    for i in range(len(answers)-1):
        if answers[i] == answer_key[i]:
            correct += 1
            correct_questions.append(str(i+1))
        else:
            incorrect += 1
            incorrect_questions.append(str(i+1))
    
    # Begin results
    
    print("DRIVER'S TEST RESULTS\n")
    # Correct answers
    print("ANSWERS CORRECT:")
    for x in correct_questions:
        print("#",x," is correct",sep="")
    print("___________\nTOTAL:",len(correct_questions))
   # Incorrect answers
    print("\nANSWERS INCORRECT:")
    for y in incorrect_questions:
        print("#",y," is incorrect",sep="")
    print("___________\nTOTAL:",len(incorrect_questions))

    # Determine if student passed
    if correct >= 15:
        result = "Congratulations! The student passed!\n"
    else:
        result = "Student did not pass the test.\n"
    print("\nRESULTS:",result)

# Generate answers.txt contents
def student():
    CONTENTS = ""
    letter = ""
    counter = 0
    while counter < 20:
        counter += 1
        choice = random.randint(1,4)
        if choice == 1:
            letter = "A"
            CONTENTS += letter+"\n"
        elif choice == 2:
            letter = "B"
            CONTENTS += letter+"\n"
        elif choice == 3:
            letter = "C"
            CONTENTS += letter+"\n"
        else:
            letter = "D"
            CONTENTS += letter+"\n"
    
    # Write contents to file
    file = open("answers.txt","w")
    file.write(CONTENTS)
    file.close()
    
main()
