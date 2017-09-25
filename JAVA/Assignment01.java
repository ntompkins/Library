/*	
Name: 		Nathan Tompkins
Project: 	CSII, Assignment 01
Completed:	9-2-17
Time Spent: 1 hour
OS: 			Ubuntu Linux
Descrip.:	This program receives input from an employee about 
				a gravel-traincar's contents, calculates the conic
				volume of the contents, and outputs all the 
				input and calculated values.
Notes:		N/A

*/

import java.util.Scanner;

public class Assignment01 {
  public static void main(String[] args) {
  // Intro to program
  System.out.println("\nConic Gravel Volume Calculator\n------------------------------\nPlease provide the following information...");
  // Data Input
    
  // Create Scanner Object
  Scanner input = new Scanner(System.in); 
  
  // prompt for employee name
  System.out.print("Full employee name: ");
  String fullName = input.nextLine();
  
  // prompt for car ID
  System.out.print("Traincar ID: ");
  String carID = input.nextLine();
  
  // prompt for gravel type
  System.out.print("Gravel type: ");
  String gravelType = input.nextLine();
  
  // prompt for radius
  System.out.print("Gravel radius: ");
  float radius = input.nextFloat();
  
  // prompt for height
  System.out.print("Gravel height: ");
  float  height = input.nextFloat();
  
  // Data Calculation
  final double PI = Math.acos(-1);
  double volume = (PI * radius * radius * height) / 3;
  
  // Data Output
   System.out.print("\nEmployee: " + fullName
       				+"\n-----------------------"
       				+"\nTrain Car: " + carID
       				+"\nRadius: " + radius
       				+"\nHeight: " + height
       				+"\nGravel Type: " + gravelType
       				+"\n-----------------------"						
       				+"\nVolume (Cubic Yards): " + volume);
}
}

/*
TEST OUTPUT

Conic Gravel Volume Calculator
------------------------------
Please provide the following information...
Full employee name: Nathan Tompkins
Traincar ID: BC34
Gravel type: A
Gravel radius: 3
Gravel height: 5

Employee: Nathan Tompkins
-----------------------
Train Car: BC34
Radius: 3.0
Height: 5.0
Gravel Type: A
-----------------------
Volume (Cubic Yards): 47.1238898038469

*/

