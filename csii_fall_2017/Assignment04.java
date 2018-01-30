/*
Name: 			Nathan Tompkins
Project: 		CSII, Assignment 04
Completed:	10.3.17
Time Spent: 1 hour
OS:					Ubuntu Linux
Descrip.:		This program makes use of a custom StopWatch
						class that records the time the computer
						takes to perform an action.
*/

import java.util.concurrent.ThreadLocalRandom;
import java.util.Arrays;

public class Assignment04 { 
	public static void main(String args[]) {
		// Create array with 100,000,000 integer values
		int[] sortingArray = new int[100000000];
		// Populate the array with numbers from 1 to 1000
		for(int i=0; i < sortingArray.length; i++) {
			sortingArray[i] = ThreadLocalRandom.current().nextInt(1, 1001);	
		}
		System.out.println("Before sorting the array, the first number is " + sortingArray[0] + " and the last number is " + sortingArray[sortingArray.length - 1] + ".\nNow let's sort the array...");
		
		// Create StopWatch object to count array sort time
		StopWatch sortTime = new StopWatch();
		
		// Sort the array
		Arrays.sort(sortingArray);
		
		// Stop the timer
		sortTime.stop();
		
		// Output the times
		System.out.print("It took " + sortTime.getElapsedTime() + " milliseconds ("+ sortTime.getElapsedTime()/1000.00 +" seconds) to sort an array with " + sortingArray.length + " numbers between 1-1000.");
		// Prove the array was sorted
		System.out.println("\nAfter sorting, the first number is " + sortingArray[0] + " and the last number is " + sortingArray[sortingArray.length - 1]);
	}
}