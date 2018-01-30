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
import java.util.concurrent.ThreadLocalRandom;
import java.util.InputMismatchException;
import java.lang.ClassNotFoundException;
import java.lang.NoSuchMethodException;

public class ExceptionHandler {

// Array index out of bounds
  public static void arrayIndexOutOfBoundsHandler(int arraySize, int arrayIndex)
    throws ArrayIndexOutOfBoundsException
  {
    // Create user defined array
    int [] userArray = new int [arraySize];
    // Populate the array
    for (int i=0; i < userArray.length; i++) {
      userArray[i] = ThreadLocalRandom.current().nextInt(1,101);
    }
    // Attempt to retrieve index
    System.out.println("Index " + arrayIndex + " = " + userArray[arrayIndex]);
  }

// String index out of bounds
  public static void stringIndexOutOfBoundsHandler(String userString, int stringIndex)
    throws StringIndexOutOfBoundsException
  {
    System.out.println("Char " + stringIndex + " = " + userString.charAt(stringIndex));
  }

// Input mismatch
  public static void inputMismatchHandler(char userChar, double userDouble)
    throws InputMismatchException
  {
    char testChar = userChar;
    double testDouble = userDouble;
    System.out.println("Char = " + testChar + ", Double = " + testDouble);
  }

// Class not found
  public static void classNotFoundHandler(int userChoice)
    throws ClassNotFoundException
  {
    if(userChoice==1) {
      Scanner tempScanner = new Scanner(System.in);
      System.out.println("\nThe scanner was created.");
    } else {
      Class className = Class.forName("false.Class");
    }
  }

// Out of memory
  public static void outOfMemoryHandler(int bigArray)
    throws OutOfMemoryError
  {
    int[] array = new int[(int)Math.pow(10,bigArray)];
    System.out.println("\nThe array was successfully created.");
  }

// No such method
  public static void noSuchMethodHandler(String methodName)
    throws NoSuchMethodException
  {
    ExceptionHandler test = new ExceptionHandler();
    Class show = test.getClass();

    switch(methodName) {
      case("pow"):
        System.out.println("10^2 = "+Math.pow(10,2));
        break;
      default:
        show.getMethod(methodName);
        break;
    }
  }
}
