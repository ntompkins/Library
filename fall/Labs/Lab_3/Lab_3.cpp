// Nathan Tompkins
// Lab 3 - 10/19/16
#include <iostream>
#include <string>
#include <ctype.h>
/*
Construct an Exam class which will grade an exam of multiple choice questions.

The Exam class should have a private member variable answerKey, which is a 
string containing the correct answers. The number of characters in the string   
determines the number of questions in the exam.  For example, if answerKey is 
"CABDE", the exam has a total of 5 questions. The correct response to question 
1 is "C", the correct response to question 2 is "A", the correct response to 
question 3 is "B", and so on.

Public member functions for the Exam class should include a default constructor, 
a single parameter constructor which sets the answerKey for the exam, getAnswerKey 
and setAnswerKey functions, and a grade function that grades and returns a 
numerical score (0-100) for the exam. The numerical score is calculated using 
the formula: (c / n) * 100, where c is the number of correct answers and n is the 
total number of questions.

Create a program which uses the Exam class.  The program should initially prompt
 the user for the exam answer key, create an Exam object, set the answer key, 
 and display the number of exam questions. Then, in a loop, prompt the user for 
 a string of answers to grade, call the exam grade function, and display the 
 numerical grade. The loop should terminate if the answer string is empty.

Extra credit will be given if the program also displays a visual indicator of 
the specific questions that were missed.

Develop and submit the Exam class definition, class implementation, and client 
program in a single (main.cpp) file.
*/
using namespace std;

class Exam {
	private:
		string answerKey;
		string incorrectAnswers;
		
	public:
		// Constructors
		Exam() {
			answerKey="";
		}
		Exam(string usrAnswerKey) {
			for(char& x : usrAnswerKey) {
				usrAnswerKey[x] = toupper(usrAnswerKey[x]);
			}
		 	answerKey = usrAnswerKey;
		}
		// Accessors
		string getAnswerKey() { return answerKey; }
		string getIncorrect() { return incorrectAnswers; }	
		
		// Mutators
		void setAnswerKey(string usrAnswerKey) { answerKey = usrAnswerKey; }
		void setIncorrect(char ch) { incorrectAnswers += ch; }
		
		// Additional functions
		int grade(int n, string usrAnswers=" ") {
			double correct = 0.0; 
			// While answers aren't blank
			if(usrAnswers != " ") {
				// Loop through user's answers
				double n = 0.0;
				for (char x : usrAnswers) {
					// Compare answer to key
					if (toupper(x) == answerKey[n++]) {
						++correct;
					}
				}
			}
			// Return final grade
			return (correct / n ) * 100.0;
		}
};

int main() {
	// Get answer key
	cout << "Enter answer key: ";
	string usrAnswerKey=""; cin >> usrAnswerKey;
	// Convert answer key to upper case
	string answerKey ="";
	for (char& x : usrAnswerKey) {
		answerKey += toupper(x);
	}
	
	// Create exam with answer key
	Exam exam(answerKey);
	cout << "Answer Key: " << exam.getAnswerKey();
	
	// Find size of answer key
	int answerKeySize=0;
	for(char& x : exam.getAnswerKey()) {
		++answerKeySize;
	}
	cout << "\nNumber of questions: " << answerKeySize << endl;
	
	// Get answers
	string usrAnswers="";
	for (int num=0; num < answerKeySize; ++num) {
		cout << "Enter answer #" << num + 1 << ": ";
		char answer=' '; cin >> answer;
		usrAnswers+=answer;
	}
	
	// Show summary of user's answers
	cout << "\nUser's Answers:\t";	
	for (char& x : usrAnswers) {
		cout << x;
	}
	
	// Calculate final grade
	int grade = exam.grade(answerKeySize, usrAnswers);
	cout << "\nFinal grade = " << grade << "%\n";
	
	
	return 0;
}
	