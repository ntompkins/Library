#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// If you allocate memory, be sure to delete it
// new to allocate, delete to deallocate

class Person {
    public:
        string name = "";
        Person *next;
};

void display(int purpose, string item, float f, int i=0) {
    switch(purpose) {
        case 1:
            cout << "The address of " << item << " is " << &item << endl;
            break;
        case 2:
            cout << "The contents of " << item << " is ";
            if (f > 0.0)
                cout << f << endl;
            else
                cout << &i << endl;
            break;
        default:
            return;
    }
}

int main () {
    float price = 0.0;
    float *p_price = &price;
    *p_price = 19.95;
    
    display(1,"price",price,0);
    display(2,"price",price,i);
    
    display(1,"p_price",0,*p_price);
    display(2,"p_price",p_price,0);
    
    cout << endl;
    
    int *p_array;
    int *p_size;
    
    Person *p_person1 = new Person;
    p_person1->name = "Harry";
    p_person1->next = nullptr;
    
    cout << "The address of p_person1 is " << &p_person1 
    << ",\nand the value of p_person1 is " << p_person1->name << endl;
    
    delete p_person1;
    
    Person *p_person2 = new Person;
    p_person2->name = "Sally";
    p_person1->next = nullptr;
    
    cout << "The address of p_person2 is " << &p_person2 
    << ",\nand the value of p_person2 is " << p_person2->name << endl;
    
    delete p_person2;
    
    return 0;
}