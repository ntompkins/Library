/*
Name:       Nathan Tompkins
Project:    CSII, Assignment 03
Completed:  9-20-17
Time spent: 1.5 hours
OS:         Ubuntu Linux
Descrip.:   This program contains an array of student IDs
            which it runs through and prompts for 4 grades 
            for each student, and finally calculates the 
            letter grade that each student earned based off 
            of the weight of each grade.
Notes:      This program is adaptable for any number of students,
            all you have to change is the number of IDs inside 
            the array labeled <studentIDs>. It does require that
            only 4 grades are desired per student, though.
            
            CONTENTS OF grades.txt:
            97.3 96.2 90.1 89.2
            88.4 85.6 81.2 80.0
            78.2 74.3 71 72.1
            61.2 63.8 64.5 65
            59.3 59.2 59.1 59
*/
import java.util.Scanner;

public class Assignment03 {
    public static void main(String args[]) {
        
        // Instantiate new scanner object
        Scanner input = new Scanner(System.in);
       
        // Create array to hold student ID's
        final String [] studentIDs = {"CR5438","YF6902","GB6540","FG6783","UJ8021"};
       
        // Create array to hold grades for all students
        double [] allGrades = new double[studentIDs.length*4];
        
        // Create master index for allGrades array
        int index = 0;
        
        // Gather grades for each student
        for(int i=0; i < studentIDs.length; i++) {
            // Prompt for input
            System.out.println("Enter grades for student " + studentIDs[i]);
            
            // Adjust prompt for each grade
            for(int j=0; j < 4; j++) {
                String[] gradeEntry = {"first", "second", "third", "fourth"};
                System.out.print("Enter the "+gradeEntry[j]+" grade: ");
                allGrades[index] = input.nextDouble();
                // Increase the master index
                index++;
            }
            // Add whitespace
            System.out.println();
        }
        
        // Loop through all grades and calculate letter grade for each student
        for(int i=0; i < studentIDs.length; i++) {
            // Add Whitespace
            if(i==0) System.out.println(); 
            double[] studentGrades = {allGrades[(i*4)],allGrades[(i*4)+1],allGrades[(i*4)+2],allGrades[(i*4)+3]};
            System.out.println(studentIDs[i]+"\t"+calculateLetterGrade(calculateAverageGrade(studentGrades)));
        }
    }
    
    // Create method to calculate the total numeric value of the student's grade
    public static double calculateAverageGrade(double[] grades) {
            return (.2*grades[0] + .2*grades[1] + .25*grades[2] + .35*grades[3]);
    }
    
    // Create method to receive a numeric grade and return the letter grade equivalent.
    public static char calculateLetterGrade(double averageGrade) {
        char grade = ' ';
        if (averageGrade >= 90) {
            grade = 'A';
        } else if (averageGrade >= 80) {
            grade = 'B';
        } else if (averageGrade >= 70) {
            grade = 'C';
        } else if (averageGrade >= 60) {
            grade = 'D';
        } else grade = 'F';
        return grade;
    }
}

/*
TEST OUTPUT 1:
$ java Assignment03
Enter grades for student CR5438
Enter the first grade: 98
Enter the second grade: 89
Enter the third grade: 92
Enter the fourth grade: 85.3

Enter grades for student YF6902
Enter the first grade: 56.2
Enter the second grade: 78.9
Enter the third grade: 98.5
Enter the fourth grade: 80

Enter grades for student GB6540
Enter the first grade: 65.8
Enter the second grade: 70
Enter the third grade: 72.3
Enter the fourth grade: 71

Enter grades for student FG6783
Enter the first grade: 69.8 
Enter the second grade: 67.9
Enter the third grade: 71.5
Enter the fourth grade: 70.2

Enter grades for student UJ8021
Enter the first grade: 50.6
Enter the second grade: 95.2
Enter the third grade: 60.4
Enter the fourth grade: 50.3


CR5438  A
YF6902  C
GB6540  C
FG6783  D
UJ8021  D

TEST OUTPUT 2:
$ java Assignment03 < grades.txt
Enter grades for student CR5438
Enter the first grade: Enter the second grade: Enter the third grade: Enter the fourth grade: 
Enter grades for student YF6902
Enter the first grade: Enter the second grade: Enter the third grade: Enter the fourth grade: 
Enter grades for student GB6540
Enter the first grade: Enter the second grade: Enter the third grade: Enter the fourth grade: 
Enter grades for student FG6783
Enter the first grade: Enter the second grade: Enter the third grade: Enter the fourth grade: 
Enter grades for student UJ8021
Enter the first grade: Enter the second grade: Enter the third grade: Enter the fourth grade: 

CR5438  A
YF6902  B
GB6540  C
FG6783  D
UJ8021  F
*/
