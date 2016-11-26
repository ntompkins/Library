/*  Nathan Tompkins  11/02/16
    Programming Fundamentals II
    Exam 2, Question 3
*/
/*
Consider the following Car structure declaration:

struct Car {
  string make, model;
  int year;
  double cost;
  Car() {make=model=""; year=0; cost=0.00;}
  Car(string mk, string md, int yr, double c) {make=mk, model=md; year=yr; cost=c;}
};

Use the Car structure declaration to create a vector of Car structures named cars
and initialize the first three elements of the vector cars with the following data:

Ford    Taurus    2014  $21,000
Honda   Accord    2012  $11,000
Jeep    Wrangler  2015  $24,000
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car {
  string make, model;
  int year;
  double cost;
  Car() { make="", model=""; year=0; cost=0.00; }
  Car(string mk, string md, int yr, double c) {make=mk, model=md; year=yr; cost=c;}
  
  /* Test function */
  void show() { cout << this->make << endl << this->model << endl << this->year << endl << this->cost << endl;}
};

int main() {
  vector<Car> cars;
  
  /* First car */
  Car ford("Ford","Taurus",2014,21000);
  cars.push_back(ford);
  
  /* ford.show(); */
  
  /* Second car */
  Car honda("Honda","Accord",2012,11000);
  cars.push_back(honda);
  
  /* honda.show(); */
  
  /* Third car */
  Car jeep("Jeep","Wrangler",2015,24000);
  cars.push_back(jeep);
  
  /* jeep.show(); */
  
  // Question 4 - Vector Loop
  for(int index=0; index < 3; index++) {
    cout << cars[index].make << endl;
    cout << cars[index].model << endl;
    cout << cars[index].year << endl;
    cout << cars[index].cost << endl;
    cout << endl;
  }
  
  return 0;
}