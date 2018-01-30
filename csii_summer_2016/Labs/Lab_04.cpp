/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Paul Thayer
 Lab 4: Sound-Distance calculator
*/
 
#include <iostream>
#include <cstdlib>
using namespace std;
 
// Create function for calculations
float calculate(string material="", double rate=0, double distance=0) 
{
    cout << "You chose " << material << " which sound travels through at " << rate << " feet per second.\n\n";
    
    bool valid_distance = false;
    do
    {
        cout << "Enter a distance in feet (0 to go back): ";
        cin >> distance;
        if (distance>0)
        {
            double travel_time = distance / rate;
            
            cout << "Sound will travel " << distance << " feet through " << material << " in " << travel_time << " seconds." << endl;
            
            valid_distance = true;
            return distance * rate;
        }
        else {
            cout << "Back to menu...\n";
            return 0;
        }
        
    } while (valid_distance=false);
} 
 
int main() 
{
    while(bool running=true) 
    {
        // Menu
        cout << "Menu: a)ir, w)ater, s)teel or q)uit: ";
        char choice = ' ';
        cin >> choice;
        choice = tolower(choice);
         
        // Declare enumerated types to navigate
        enum Materials {
            air = 'a', 
            water = 'w', 
            steel = 's', 
            quit = 'q'
        }; 

        // Run calculations through function
        switch (choice) 
        {
            case air: 
                calculate("air", 1100); // 1100 f/s
                break;
            
            case water: 
                calculate("water", 4900);
                break;
            
            case steel: 
                calculate("steel", 16400);
                break;
            
            case quit: 
                cout << "\nGoodbye!\n"; 
                return 0;
           
            default: 
                cout << "Invalid option. Please enter a, w, s, or q." << endl; 
                break;
        }
    }
    
    return 0;
}

/*
TEST OUTPUT

Menu: a)ir, w)ater, s)teel or q)uit: a                                                                                                                                                        
You chose air which sound travels through at 1100 feet per second.                                                                                                                            
                                                                                                                                                                                              
Enter a distance in feet (0 to go back): 1100                                                                                                                                                 
Sound will travel 1100 feet through air in 1 seconds.                                                                                                                                         
Menu: a)ir, w)ater, s)teel or q)uit: w                                                                                                                                                        
You chose water which sound travels through at 4900 feet per second.                                                                                                                          
                                                                                                                                                                                              
Enter a distance in feet (0 to go back): 4900                                                                                                                                                 
Sound will travel 4900 feet through water in 1 seconds.                                                                                                                                       
Menu: a)ir, w)ater, s)teel or q)uit: s                                                                                                                                                        
You chose steel which sound travels through at 16400 feet per second.                                                                                                                         
                                                                                                                                                                                              
Enter a distance in feet (0 to go back): 16400                                                                                                                                                
Sound will travel 16400 feet through steel in 1 seconds.                                                                                                                                      
Menu: a)ir, w)ater, s)teel or q)uit: a                                                                                                                                                        
You chose air which sound travels through at 1100 feet per second.                                                                                                                            
                                                                                                                                                                                              
Enter a distance in feet (0 to go back): 0                                                                                                                                                    
Back to menu...             
Menu: a)ir, w)ater, s)teel or q)uit: A
You chose air which sound travels through at 1100 feet per second.

Enter a distance in feet (0 to go back): 0
Back to menu...
Menu: a)ir, w)ater, s)teel or q)uit: o
Invalid option. Please enter a, w, s, or q.
Menu: a)ir, w)ater, s)teel or q)uit: q                                                                                                                                                        
                                                                                                                                                                                              
Goodbye!     
*/