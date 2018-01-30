/*
  Nathan Tompkins
  Assignment 06
*/

import java.util.Scanner;
import java.io.*;

public class Assignment06 { 
  public static void main(String[] args) throws IOException {
    
    // Open input file
    File inFile = new File("employeePay.txt");
    
    // Create scanner of inFile
    Scanner inFileContents = new Scanner(inFile);
    
    // Create 2 arrays
    String[][] employeeNames = new String[100][2];
    double[][] hoursAndPay = new double[100][3];
    
    // Read contents into arrays
    for(int i = 0; i < employeeNames.length; i++) {
      // First name
      employeeNames[i][0] = inFileContents.next();
      // Last name
      employeeNames[i][1] = inFileContents.next();
      // Employee's hours   
      hoursAndPay[i][0] = inFileContents.nextFloat();
      // Employee's pay
      hoursAndPay[i][1] = inFileContents.nextFloat();;
    }
    
    // Create output file
    java.io.PrintWriter outFile = new java.io.PrintWriter("payCheckInfo.txt");
    
    // calculate gross pay
    calculatePay(employeeNames, hoursAndPay);
    
    // Close the output file
    outFile.close();
  }
  // File to calculate gross pay
  public static void calculatePay(String[][] names, double[][] hoursAndPay) {
    for(int j = 0; j < names.length; j++){
      double grossPay = hoursAndPay[j][0] * hoursAndPay[j][1];
      double ssTax = grossPay * .0625;
      double incomeTax = grossPay * .075;
      hoursAndPay[j][2] = grossPay - ssTax - incomeTax;
    }
  }
}
/*
employeePay.txt contents

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