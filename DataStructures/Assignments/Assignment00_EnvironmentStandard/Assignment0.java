/*
  Data Structures
  - - - - - - - -
  Assignment 00: Low-Hanging Fruit
  Author: Nathan Tompkins
  Date Complete: 01.09.2018
  Description:
    This program gets a string and an integer from the user.
    If the integer entered is even, only the even characters are printed,
    but if the integer is odd, then only the odd characters are printed.
*/

import java.util.Scanner;

public class Assignment0 {
  public static void main(String[] args) {

    // Create input scanner
    Scanner input = new Scanner(System.in);

    // Get user's favorite quote
    System.out.print("Enter your life motto: ");
    String quote = input.nextLine();

    // Get user's favorite number
    System.out.print("Enter your favorite number: ");
    int number = input.nextInt();

    // Check if number is even or odd
    if(number % 2 == 0) {

      // Loop through the entire string and output even characters
      for(int x=1; x < quote.length(); x+=2) {
        System.out.print(quote.charAt(x));
      }
    } else {

      // Loop through the string and output odd characters
      for(int y=0; y < quote.length(); y+=2) {
        System.out.print(quote.charAt(y));
      }
    }

    // Ending message
    System.out.println(
      "\nThank you for sharing this information.\nThe program will now end."
    );
  }
}
