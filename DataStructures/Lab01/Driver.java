/*
  Data Structures
  - - - - - - - -
  Lab 01: MyStackLab
  Author: Nathan Tompkins
  Date Completed: 1.29.2018
  Purpose: To create a custom stack data structure
  for use in future assignments.
*/

import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        
        // Create scanner object
        Scanner input = new Scanner(System.in);
        
        try {
            // Welcome message
            System.out.println("This is a driver class for a "+
            "custom stack data structure.\nThis class will "+
            "receive a line of input from the user and then call "+
            "all of the methods built in to test the stack.");
            
            // Create stack object
            NathansStack<String> stack = new NathansStack<String>();
            
            // Get line of input
            System.out.print("Enter input: ");
            String usrInput = input.nextLine();
            
            // Test if isEmpty() works
            if(stack.isEmpty()) 
                System.out.println("isEmpty() test 1: The stack is empty.");
            
            // Add elements to the stack
            for(int i=0; i < usrInput.length(); i++) {
                stack.push(""+usrInput.charAt(i));
            }
            
            // test isEmpty() again
            if(!stack.isEmpty())
                System.out.println("isEmpty() test 2: The stack is no longer empty.");
            
            // test top()
            System.out.println("top() test: The top of the stack is: "+stack.top());
            
            // test pop()
            stack.pop();
            System.out.println("pop() test: After calling .pop(), the top "
            +"of the stack is: "+stack.top());
            
            System.out.println("The program will now end. Thank you.");
            
        } catch (Exception e) {
            System.out.print(e);
        }
    }
}