/*
Name: Nathan Tompkins
Project: CSII, Assignment 05
Completed: 10.31.2017
Time Spent: 4 hours
OS: Ubuntu Linux
Description: This program uses the try-catch feature
  of JAVA to deal with exceptions as the program runs.
  It is prepared to deal with 6 different exceptions
  and provides a menu for the user to choose the
  exception they want to trigger. It also allows the
  user to execute the code without causing it to fail.
Notes: None.
*/

import java.util.Scanner;
import java.util.InputMismatchException;
import java.lang.OutOfMemoryError;
import java.lang.ClassNotFoundException;
import java.lang.NoSuchMethodException;

public class Assignment05 {
  public static void main(String args[]) {

    // Instantiate Exception Object
    ExceptionHandler userException = new ExceptionHandler();
    // Instantiate Scanner Object
    Scanner input = new Scanner(System.in);

    // Try-Catch block with menu
    try {
      System.out.print(
        "Exception Handling Program\n" +
        "--------------------------\n" +
        "1) ArrayIndexOutOfBoundsException\n" +
        "2) StringIndexOutOfBoundsException\n" +
        "3) InputMismatchException\n" +
        "4) ClassNotFoundException\n" +
        "5) OutOfMemoryError\n" +
        "6) NoSuchMethodException\n" +
        "0) Quit\n" +
        "Enter the error you want to check (1-6): "
      );

      // Act on user's input
      int menuChoice = input.nextInt();

      // Call corresponding method
      switch(menuChoice) {
        case 0:
          System.exit(0);

        case 1: // ArrayIndexOutOfBounds
          System.out.print("Enter the size of your array: ");
          int arraySize = input.nextInt();
          System.out.print("Enter the index you want to check: ");
          int arrayIndex = input.nextInt();

          // Call the exception handling method
          userException.arrayIndexOutOfBoundsHandler(arraySize,arrayIndex);
          break;

        case 2: // StringIndexOutOfBoundsException
          System.out.print("Enter a word: ");
          String userString = input.next();
          System.out.print("Enter the index of the word you want to check: ");
          int stringIndex = input.nextInt();

          // Call the exception handling method
          userException.stringIndexOutOfBoundsHandler(userString, stringIndex);
          break;

        case 3: // InputMismatchException
          System.out.print("Enter a character: ");
          char userChar = input.next().charAt(0);
          System.out.print("Enter a double: ");
          double userDouble = input.nextDouble();

          // Call the exception handling method
          userException.inputMismatchHandler(userChar, userDouble);
          break;

        case 4: // ClassNotFoundException
          System.out.print("\nWould you like to try..." +
                          "\n1) Instantiating the Scanner class, or" +
                          "\n2) Instantiating a fake class" +
                          "\nChoice: ");
          int userChoice = input.nextInt();

          // Call the exception handling method
          userException.classNotFoundHandler(userChoice);
          break;

        case 5: // OutOfMemoryError
          System.out.print("Enter a power for your array: ");
          int bigArray = input.nextInt();

          // Call the exception handling method
          userException.outOfMemoryHandler(bigArray);
          break;

        case 6: // NoSuchMethodException
          System.out.print("\nEnter the name of a method to call (pow): ");
          String methodName = input.next();

          // Call the exception handling method
          userException.noSuchMethodHandler(methodName);
          break;
      }
    }
    catch(ArrayIndexOutOfBoundsException ex) {
      System.out.println("\nError: The entered index was invalid.");
    }
    catch(StringIndexOutOfBoundsException ex) {
      System.out.println("\nError: The entered index was invalid.");
    }
    catch(InputMismatchException ex) {
      System.out.println("\nError: The input did not match the data type.");
    }
    catch(ClassNotFoundException ex) {
      System.out.println("\nError: The class was not found.");
    }
    catch(OutOfMemoryError ex) {
      System.out.println("\nError: The program ran out of memory.");
    }
    catch(NoSuchMethodException ex) {
      System.out.println("\nError: The method was not found.");
    }
  }
}
