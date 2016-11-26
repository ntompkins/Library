/*  
Nathan Tompkins
Exam 2, Question 5
*/
#include <iostream>
#include <string>
using namespace std;

string DecimalToRoman(int);

int main() {
    cout << "Enter an integer: ";
    int usrNumber=0; cin >> usrNumber;
    cout << DecimalToRoman(usrNumber);
    
    return 0;
}

string DecimalToRoman(int usrNumber) {
    string romanNumber="";
    int values[13] 		= {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string romans[13] 	= {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
	int index=13;
	while(index >= 0) {
		if(usrNumber - values[index] >= 0) {
			usrNumber-=values[index];
			romanNumber+=romans[index];
		} else {
		    index--;
		}
	} 
    return romanNumber;
}
