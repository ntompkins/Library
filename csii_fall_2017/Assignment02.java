/*
Name: 		Nathan Tompkins
Project:		CSII, Assignment 02
Completed:	9-13-17
Time spent: 2 hours
OS:			Ubuntu Linux
Descrip.:	This program will generate the lowest 
				final exam score a student needs in
				order to earn their desired grade
				given their past grade averages.
Notes:		N/A
*/

import java.util.Scanner;

public class Assignment02 {
  public static void main(String args[]) {
    
    // Instantiate new scanner object
    Scanner input = new Scanner(System.in);
    
    // Program Intro
    System.out.println("Grade Calculator\nPlease enter the following averages...");
    
    // Record initial averages
   	// user's quiz average
    System.out.print("Quiz average: ");   
    double quizAvg = input.nextDouble();        
   	// user's assignment average
    System.out.print("Assignment average: ");
    double assignmentAvg = input.nextDouble();  
   	// user's project average
    System.out.print("Project average: ");
    double projectAvg = input.nextDouble();     
    
    // Begin input loop
    while(true) { 
    	// Output menu
      System.out.print("Enter the letter grade you want.\nA), B), C), D), F), Q)uit: ");
      // Get input char and convert to uppercase
      char desiredGrade = Character.toUpperCase(input.next().charAt(0));
      // Quit if the user wants to
      if (desiredGrade == 'Q') break;
      
      // Set lower bound based off of desired grade
      double bound = 0;
      switch(desiredGrade) {
	      case('A'):
	        bound = 90;
	        break;
	      case('B'): 
	        bound = 80;
	        break;
	      case('C'): 
	        bound = 70;
	        break;
	      case('D'):
	        bound = 60;
	        break;
	      case('F'): 
	        bound = 50;
	        break;
    	}
     
      // Calculate desired grade
    	double requiredGrade = calculateGrade(quizAvg, assignmentAvg, projectAvg, bound);
    	
    	// Tell the user what they need to get that grade
    	if(requiredGrade>100) {
    		System.out.println("\nYou can not earn " + ((desiredGrade=='A')?"an ":"a ") + desiredGrade + " given your averages.\n");
    	} else if (requiredGrade<=0) {
    		System.out.println("\nYou do not need to take the final exam to earn " + ((desiredGrade=='A')?"an ":"a ") + desiredGrade +'\n');
    	}
    	else {
    		System.out.println("\nTo earn " + ((desiredGrade=='A')?"an ":"a ") + desiredGrade + " you will need a score of " + requiredGrade + " on your final.\n");
    	}
    } 
  }
  
  // Method parameters: Quiz average, assignment average, project average, lower bound = number not char
  public static double calculateGrade(double quiz, double assignment, double project, double bound) {
    return ((-0.5 * quiz + -0.5 * assignment + -0.5 * project) + (2.5 * bound));
  }
  
}
/*
TEST OUTPUT

Grade Calculator
Please enter the following averages...
Quiz average: 95
Assignment average: 86
Project average: 85.2
Enter the letter grade you want.
A), B), C), D), F), Q)uit: a

To earn an A you will need a score of 91.9 on your final.

Enter the letter grade you want.
A), B), C), D), F), Q)uit: b

To earn a B you will need a score of 66.9 on your final.

Enter the letter grade you want.
A), B), C), D), F), Q)uit: c

To earn a C you will need a score of 41.900000000000006 on your final.

Enter the letter grade you want.
A), B), C), D), F), Q)uit: d

To earn a D you will need a score of 16.900000000000006 on your final.

Enter the letter grade you want.
A), B), C), D), F), Q)uit: f

You do not need to take the final exam to earn a F

Enter the letter grade you want.
A), B), C), D), F), Q)uit: q
*/
