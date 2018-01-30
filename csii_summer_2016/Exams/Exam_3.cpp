/*
  COSC 1337 Exam 3 Lab portion Summer 2016
  Name: Nathan Tompkins
  Filename: MW16_Tompkins_X3.cpp
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ----------------------------------------------
// The section below is provided startup code for step 1. DO NOT CHANGE UNLESS COMPLIER ERROR.
// Below, a vector is used. It is like an array. Don't worry about the syntax.
// It creates an vector (array) as described in the instructions. It provides
// intial startup data for you to save time. Use this data to load your store with items.
struct T {string name; double price; string made_in; int weight;};
vector<T> stuff {
  {"hat", 8.00, "china", 6},
  {"t-shirt", 15.00, "usa", 14},
  {"coffee mug", 6.50, "canada", 22},
  {"candy bar", 0.79, "mexico", 3},
  {"", 34.59, "japan", 122},
  {"mixing bowl", 4.99, "brazil", 20}
};

void show_stuff() { // verify that stuff contains the data as specified.
  cout<<"Contents of vector stuff, already loaded:\n";
  for (auto &t:stuff) { // If this does not compile, see the note below
    cout<<setw(12)<<t.name<<setw(8)<<t.price<<setw(8)<<t.made_in<<setw(6)<<t.weight<<endl;
  }
  cout<<endl;
}
// If the for (auto &t:stuff) code has a compilation error, you can do this:
//   1) recommended: enable C++11/14 features on your compiler with option: -std=c++11
//   2) alternative: change to a regular for loop: for (int i=0; i<stuff.length(); ++i), etc.
// The section above is provided startup code. DO NOT CHANGE UNLESS COMPILER ERROR
// ----------------------------------------------

// Put class Item definition code for steps 1 and 2 here.
class Item {
  public:
    string item_name;
    double item_cost;
    
  Item() {  // Default constructor
    item_name = "Invalid"; // Defaults to invalid
    item_cost = 1.00;      // with price of 1.00
  }
  
  Item(string desired_name, double desired_cost) {  // User specified attributes constructor
    
    if (desired_name.length() >= 1)  // Item name must be at least 1 character
      item_name = desired_name;
    else
      item_name = "Invalid";
      
    if (desired_cost >= 1.00)       // Item must cost at least 1.00
      item_cost = desired_cost;
    else 
      item_cost = 1.00;
  }
  
  void display() {
    cout << item_name << "\t\t$" << fixed << setprecision(2) << item_cost << endl;
    return;
  }
};

void step1() {
  cout<<"\nStep 1:\n";
  show_stuff(); // Provided startup code to demonstrate that stuff contains initial startup data.
  // Put testing code for step 1 here:
  
  Item soap;
  soap.item_name="Soap";
  soap.item_cost=1.25;
  soap.display();
  
  // Test constructor for input validation
  Item candle("",0.50);
  candle.display(); // Should display Invalid   $1.00
  
  Item matches("Matches",1.50);
  matches.display();
  
  cout << "\nStore Inventory\n"
       << setw(10) << "Name\t"
       << "Price\n";
  Item store[6];
  
  for (int i=0; i < sizeof(store)/sizeof(store[0]); ++i) {
    store[i].item_name = stuff[i].name;
    store[i].item_cost = stuff[i].price;
    
    cout << setw(10)
         << store[i].item_name 
         << "\t$" 
         << store[i].item_cost 
         << endl;
  }
}

void step2() {
  cout<<"\nStep 2:\n";
  // Put all your code for step 2 here:
  Item *umbrella = new Item;
  string *p_item_name = &umbrella->item_name;
  double *p_item_cost = &umbrella->item_cost;
  
  *p_item_name = "Black Umbrella";
  *p_item_cost = 19.95;
  
  umbrella->display();
  
  cout << "Umbrella is located at " << &umbrella;
  delete umbrella;
  umbrella = nullptr;
}

// Step 3: The initial code for class Number is provided. You will add to it further down...
class Number {
  private:
    int number;
  public:
    Number(int n) {
      number=n;
    }
    int get() {
      return number;
    }
    // operator+
    friend Number operator+(const Number&, const Number&);
    Number operator+(Number& num) {
      num.number = this->number + num.number;
      return num;
    }
    // operator++
    Number& operator++() {
        ++number;
        return *this;
    }
    Number operator++(int) {
        Number num(*this);
        operator++(); // pre-increment
        return num;
    }
    // operator--
    Number& operator--() {
        --number;
        return *this;
    }
    Number operator--(int) {
        Number num(*this);
        operator--(); // pre-decrement
        return num;
    }
};
  
void step3() {
  cout<<"\nStep 3:\n";
  // This is testing code for step 3.
  // After you have implemented: operator++, operator--, and operator+,
  // Uncomment the code below. It should work.
  Number a=4; ++a; ++a; cout<<"a="<<a.get()<<endl; // test code, expect: 6, uncomment when ready
  Number b=5; --b; --b; cout<<"b="<<b.get()<<endl; // test code, expect: 3, uncomment when ready
  Number c=6, d=7, e=c+d;                          // test code, uncomment when ready
  cout<<"e="<<e.get()<<endl<<endl;                 // test code, expect: 13, uncomment when ready
  // add code here to initialize Number evens[] with 2 4 6 8 10 and display its contents
  /*Number evens[5];
  int next_even=2;
  for (int i=0; i < sizeof(evens)/sizeof(evens[0]); ++i) {
    evens[i].number = next_even;
    cout << evens[i].number;
    next_even+=2;
  }*/
};

// The code below is for step 4, recursion
// This startup code may be helpful when developing your recursive functions.
void recurse(int times_to_call) {
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... " << "("<<times_to_call<<") " <<endl;
  if (times_to_call>1) {
    cout << "recurse before call... " << "("<<times_to_call<<") " <<endl;
    recurse(times_to_call-1); // work can also be done inside the parameter list!
    cout << "recurse after call... " << "("<<times_to_call<<") " <<endl;
  } else {
    cout << "recurse else option... " << "("<<times_to_call<<") " <<endl;
  }
  cout << "recurse ...tail " << "("<<times_to_call<<") " <<endl;
}

// Below are working iterative versions of line, left_arrow, right_arrrow, double_arrow
void line_iterative(int n) { // Provided, do not change
  for (int i=0; i<n; ++i)
    cout<<"-";
}

void left_arrow_iterative(int n) { // Provided, do not change
  cout<<"<";
  for (int i=0; i<n; ++i)
    cout<<"-";
}

void right_arrow_iterative(int n) { // Provided, do not change
  for (int i=0; i<n; ++i)
    cout<<"-";
  cout<<">";
}

void double_arrow_iterative(int n) { // Provided, do not change
  cout<<"<";
  for (int i=0; i<n; ++i)
    cout<<"-";
  cout<<">";
}

// Put your new recursive versions for step 4 here...
void line(int n) {
   // fill this in with recursive code for line


}

void left_arrow(int n) {
   // fill this in with recursive code for left_arrow


}

void right_arrow(int n) {
   // fill this in with recursive code for right_arrow


}

void double_arrow(int n) {
  // This one is a challenge. Hint: add another parameter
  // fill this in with recursive code for double_arrow


}

void step4() {
  // Below is testing code for step 4. No changes needed.
  // recurse(3); // call to recurse example for experimentation, if desired
  cout<<"Step 4:\n";
  cout<<"Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n=1; n<=5; ++n) { // test provided iterative functions
    cout<<"n="<<setw(2)<<n<<":";
    line_iterative(n); cout<<' ';
    left_arrow_iterative(n); cout<<' ';
    right_arrow_iterative(n); cout<<' ';
    double_arrow_iterative(n); cout<<endl;
  }
  cout<<"\nTest student's new recursive versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n=1; n<=5; ++n) { // test student's new recursive functions
    cout<<"n="<<setw(2)<<n<<":";
    line(n); cout<<' ';
    left_arrow(n); cout<<' ';
    right_arrow(n); cout<<' ';
    double_arrow(n); cout<<' '<<endl;
  }
};

void step5() {
  // 5 different ways to cause undefined behavior, and possibly crash a C++ program.
  // in main, step5() is commented out.
  // To verify your bad code is really bad, test it by uncommenting step5() in main.
  cout<<"Step 5:\n";
  // Put all your code for step 5 here:


};

int main() {
  // No new code goes in main. Put all new code where designated in the steps above.
  cout<<"Start...\n";
  step1();
  step2();
  step3();
  step4();
  // step5(); // Extra credit: 5 ways to possibly crash a C++ program
  cout<<"\n...end.\n";
	return 0;
}

/* Original startup code test output:
Start...
Step 1:
Contents of vector stuff, already loaded:
         hat       8   china     6
     t-shirt      15     usa    14
  coffee mug     6.5  canada    22
   candy bar    0.79  mexico     3
               34.59   japan   122
 mixing bowl    4.99  brazil    20

Step 2:
Step 3:
Step 4:
Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

Test student's new recursive versions of line, left_arros, right_arrow, double_arrow:
n= 1:
n= 2:
n= 3:
n= 4:
n= 5:

...end.
*/


/* Paste your test output here:
Start...

Step 1:
Contents of vector stuff, already loaded:
         hat       8   china     6
     t-shirt      15     usa    14
  coffee mug     6.5  canada    22
   candy bar    0.79  mexico     3
               34.59   japan   122
 mixing bowl    4.99  brazil    20

Soap            $1.25
Invalid         $1.00
Matches         $1.50

Store Inventory
     Name       Price
       hat      $8.00
   t-shirt      $15.00
coffee mug      $6.50
 candy bar      $0.79
                $34.59
mixing bowl     $4.99

Step 2:
Black Umbrella          $19.95
Umbrella is located at 0x7ffcd5b64d48
Step 3:
a=6
b=3
e=13

Step 4:
Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

Test student's new recursive versions of line, left_arrow, right_arrow, double_arrow:
n= 1:    
n= 2:    
n= 3:    
n= 4:    
n= 5:    

...end.
*/