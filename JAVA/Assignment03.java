/*
Name:       Nathan Tompkins
Project:    CSII, Assignment 03
Completed:  9-20-17
Time spent: 1 hour
OS:         Ubuntu Linux
Descrip.:   This program recieves an array of student IDs,
            then prompts for 4 grades for each student,
            and finally calculates the letter grade that
            each student earned based off of the weight
            of each grade.
Notes:      This program is adaptable for any number of students,
            all you have to change is the number of IDs inside 
            the array labeled <studentIDs>.
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
NOTES

// Student ID Grade // Don't output this line
// KR1275  A

// Weight  = 20% 20% 25% 35%
// We can hardcode the ID's into an array
// No more than 30 students will be entered

// Input should look like this
// For student <studentID>
// Please enter the <first/second/third/fourth> grade:
// Four scores for each students
// All the scores should be in _one_ array: all grades entered are in the same array and are held in groups of four.
// Use copyarray to pass four values into a separate method and calculate average grade
// average grade will then be passed into another method that will calculate the letter grade

// First step is to get all the scores for all the students and put it into a single array
// Grades should be entered as number grades, not letter grades: 98.7 95.2 86.3 89.5
*/
