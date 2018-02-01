/*
  Data Structures
  - - - - - - - -
  Assignment 01: Nonograms Checker
  Author: Nathan Tompkins
  Date Complete: 01.19.2018
  Description: This program verifies a given
    nonogram size, hint list, and possible solution.
    It does not solve the nonogram, it only verifies
    the solution as possible or not possible.
*/
import java.util.Scanner;
import java.lang.Math;

public class Assignment1 {
  public static void main(String[] args) {

    // Create scanner object
    Scanner input = new Scanner(System.in);

    // Get nonogram size from user
    System.out.print("Enter number of rows: ");
    final int rows = input.nextInt();
    System.out.print("Enter number of cols: ");
    final int cols = input.nextInt();

    // Create 2d array to hold hints
    String [][] hints = new String [2][Math.max(rows,cols)];

    // Consume the newline character
    input.nextLine();

    // Loop through rows and get hints
    for(int r=0; r < rows; r++) {
      System.out.print("Enter hint for row "+r+": ");
      hints[0][r] = input.nextLine();
    }
    // Loop through cols and get hints
    for(int c=0; c < cols; c++) {
      System.out.print("Enter hint for col "+c+": ");
      hints[1][c] = input.nextLine();
    }
    // Create 2d array to hold solution
    boolean [][] solution = new boolean [rows][cols];

    // Get solution input
    for(int r=0; r < rows; r++) {

      // Get the current line in the solution
      String currentLine = input.nextLine();

      // Remove spaces
      currentLine = currentLine.replace(" ","");

      // Loop through the characters in the line
      for(int x=0; x < currentLine.length(); x++) {

        // Update the values for characters
        if(currentLine.charAt(x)=='0') {
          solution[r][x] = false;
        }
        if(currentLine.charAt(x)=='1') {
          solution[r][x] = true;
        }

        // TEST
        // System.out.print(r+","+x+": "+solution[r][x]+'\n');
      }
    }

    // Create nonogram object
    Nonogram nonogram = new Nonogram(hints, solution, rows, cols);

    // Output solution
    // System.out.println('\n'+nonogram.toString());

    // Print validity
    if(nonogram.checker()) {
      System.out.println(
        "\nThe solution is valid.\nThe program will now end"
        );
    }
    else {
      System.out.println(
        "\nThe solution is invalid.\nThe program will now end."
        );
    }
    // Close input scanner
    input.close();
  }
}
