#include <iostream>
using namespace std;

int main() {
	// Loop to 100
	for (int const i=1; i < 101; ++i) {
		switch(i) {
			case(i%3==0):
				cout<<"Fizz";
			case(i%5==0):
				cout<<"Buzz";
			default:
				cout<<i;
		}
		cout << endl;
		// if (i%3==0) cout<<"Fizz";
		// if (i%5==0) cout<<"Buzz";
		// if (i%3>0&&i%5>0) cout<<i;
		// cout << endl;
		
		
		// if (i % 3 == 0 && i % 5 == 0)
		// 	cout << "FizzBuzz\n";
		// else if (i % 3 == 0)
		// 	cout << "Fizz\n";
		// else if (i % 5 == 0)
		// 	cout << "Buzz\n";
		// else
		// 	cout << i << endl;
	}
	return 0;
}