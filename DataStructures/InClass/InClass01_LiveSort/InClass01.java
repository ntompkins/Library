import java.util.Scanner;

public class InClass01 {
 public static void main(String[] args) {
  // Create array & limit size to 50
  int [] userValues = new int [20];
  
  // Get input from user
  Scanner input = new Scanner(System.in);
  
  int num = 0;
  
  // Each time they enter a number, print out the array
  for(int i=0; i < userValues.length; i++) {
   
   // Prompt for input
   System.out.print("Enter next value (0 to quit): ");
   
   // Get next line of input
   num = input.nextInt();
   
   // Sentinel if
   if(num==0) break;
   
   // Set next array value
   userValues[i] = num;
   
   // Sort array
   sort(userValues);
   
   // Print out array values
   for(int j=0; j<20; j++) {
    //if(userValues[j]!=0)
     System.out.print(userValues[j]+" ");
   }
   System.out.println();
  }
 }
 
 public static void sort(int[] numbers) {
  int n = numbers.length;
  for(int k = 1; k < n; k++) {
   int cur = numbers[k];
   int j = k;
   while(j > 0 && numbers[j-1] > cur) {
    numbers[j] = numbers[j-1];
    j--;
   }
   numbers[j] = cur;
  }
 }
}



