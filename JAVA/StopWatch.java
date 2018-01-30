/*
Name: 			Nathan Tompkins
Project: 		CSII, Assignment 04
Completed:	10.3.17
Time Spent: 1 hour
OS:					Ubuntu Linux
Descrip.:		This class records the time taken to perform
						actions in a program.
*/

public class StopWatch {
  // Private variables startTime & endTime
	private long startTime;
	private long stopTime;
	
	// Constructor ==> Set startTime to current time
	StopWatch() {
		start();
	}

	// Getters	
	long getStartTime() {
		return startTime;	
	}
	long getStopTime() {
		return stopTime;	
	}

	// * start method resets startTime to the current time ==> doesn't accept input
	void start() {
		startTime = System.currentTimeMillis();
	}
	// * stop method sets stopTime to the current time ==> doesn't accept input
	void stop() {
		stopTime = System.currentTimeMillis();
	}
	// * getElapsedTime method returns difference between stopTime and startTime
	long getElapsedTime() {
		return getStopTime() - getStartTime();
	}  
}
