/*
Name: Nathan Tompkins
Project: CSII, Assignment 07
Completed: 11.13.2017
Time Spent: 2 hours
OS: Ubuntu Linux
Description: This program takes an input of employee names, hours worked, and
  payrate, calculates all of the necessary tax information, and then
  outputs the results to a file of the user's choice.

employeePay.txt contents:

John Jones 38 18.15
Bill Peterson 41 11.07
Tim Tompson 45 19.51
Harry Smith 36 18.55
James Johnson 40 17.12
Jill Patterson 42 19.76
Alice Williams 36 14.79
Mary Watson 45 16.99
Alex Stanley 44 20.03
Kevin Boatman 40 19.75
Joe Jones 41 13.39

*/

import java.util.Scanner;
import java.io.*;
import java.text.NumberFormat;

public class Assignment07 {
public static void main(String[] args) throws IOException {
  // input Scanner
  Scanner input = new Scanner(System.in);

  try {
    // Get input file name
    System.out.print("Input file name: ");
    String inputFileName = input.next();
    // Read input file contents
    Scanner employeeData = new Scanner(new File(inputFileName));

    // Get output file name
    System.out.print("Output file name: ");
    String outputFileName = input.next();

    // create arrays for employeeData
    String[][] employeeNames = new String[100][2];
    /* Array Contents:
       [0] First Name, [1] Last Name
     */
    double[][] employeeWages = new double[100][7];
    /* Array Contents:
       [0] Hours, [1] Pay Rate, [2] Regular Pay,
       [3] Overtime Pay, [4] Income Tax, [5] SS Tax,
       [6] Net Pay
     */

    // Read employee data into arrays
    int index = 0;
    while(employeeData.hasNext()) {
      employeeNames[index][0] = employeeData.next();
      employeeNames[index][1] = employeeData.next();
      employeeWages[index][0] = employeeData.nextDouble();
      employeeWages[index][1] = employeeData.nextDouble();
      index++;
    }

    // Create PrintWriter for output file
    PrintWriter out = new PrintWriter(new File(outputFileName));
    while(true) {
      // Get information on user's desired employees
      System.out.print("Employee Number (0 to stop): ");
      int employee = input.nextInt();
      // break out of loop if user is done, or if employee doesn't exist
      if (employee == 0) {
        System.out.println("The program will now stop...");
        break;
      }
      // Calculate information for selected employee
      calculatePay(employee, employeeWages);
      // Write out contents of array
      out.print(
      employeeNames[employee - 1][1] + ", " +
      employeeNames[employee - 1][0] +
      "\n---------------------\n"
      );
      out.printf("Regular Pay:  $%,.2f%n", employeeWages[employee-1][2]);
      out.printf("Overtime Pay: $%,.2f%n", employeeWages[employee-1][3]);
      out.printf("Income Tax:   $%,.2f%n", employeeWages[employee-1][4]);
      out.printf("SS Tax:       $%,.2f%n", employeeWages[employee-1][5]);
      out.print("---------------------\n");
      out.printf("Net Pay:      $%,.2f%n", employeeWages[employee-1][6]);
      out.println('\n');
    }
    // Close the output file
    out.close();

    // Farewell message
    System.out.println("Your employee information file, " +
                       outputFileName + ", has been created.");

  }
  catch(IOException e) {
    System.out.println("\nError: The file was not found.");
  }
  catch(ArrayIndexOutOfBoundsException e) {
    System.out.println("\nError: The array index was out of bounds.");
  }
}
public static void calculatePay(int employee, double[][] wages) {
  int ID = employee-1;
  // Check for overtime
  double overtimePay = 0.0;
  if(wages[ID][0] > 40.0) {
    double overtime = wages[ID][0] - 40.0;
    double overtimeRate = wages[ID][1] * 1.5;
    overtimePay = overtime*overtimeRate;
  }
  // Calculate all pay information
  double grossPay = wages[ID][0] * wages[ID][1] + overtimePay;
  double ssTax = grossPay * 0.0625;
  double incomeTax = grossPay * 0.075;
  double netPay = grossPay - ssTax - incomeTax;
  // Populate Array
  wages[ID][2] = grossPay;
  wages[ID][3] = overtimePay;
  wages[ID][4] = incomeTax;
  wages[ID][5] = ssTax;
  wages[ID][6] = netPay;
}
}
/*
EXAMPLE OUTPUT

Input file name: employeePay.txt
Output file name: output.txt
Employee Number (0 to stop): 1
Employee Number (0 to stop): 3
Employee Number (0 to stop): 5
Employee Number (0 to stop): 7
Employee Number (0 to stop): 2
Employee Number (0 to stop): 9
Employee Number (0 to stop): 0
The program will now stop...
Your employee information file, output.txt, has been created.

***************************

EXAMPLE OUTPUT FILE CONTENTS

Jones, John
---------------------
Regular Pay:  $689.70
Overtime Pay: $0.00
Income Tax:   $51.73
SS Tax:       $43.11
---------------------
Net Pay:      $594.87


Tompson, Tim
---------------------
Regular Pay:  $1,024.28
Overtime Pay: $146.33
Income Tax:   $76.82
SS Tax:       $64.02
---------------------
Net Pay:      $883.44
*/
