/*
 Author: Nathan Tompkins
 Course: COSC 1337 Summer 2016 MW16
 Instructor: Paul Thayer
 Lab 5: Population bar chart generator
*/

/* people.txt content
2000   4000   5000   9000   14000   18000   30000   9000   2000   4000   1000   
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() 
{
    // Set file name to const str
    const string inFileName="people.txt";
    // Open file
    ifstream inFile(inFileName);

    if (inFile)
    {
        // File open confirmation
        cout << "The file " << inFileName << " was successfully opened.\n\n";
       
        // Output interface head
        cout << "PRAIRIEVILLE POPULATION GROWTH\n"
             << "(each * represents 1000 people)\n\n"
             << setw(6) << left << "YEAR" 
             << setw(30) << left << "POPULATION" << endl;
        
        int interval_count = 1910;  // Variable to count how many intervals are in the file
        while(!inFile.eof())     // Loop until eof reached
        {
            int population;      // Variable to population
            inFile >> population;   // Store the file's next value in population
            
            if(inFile.eof())        // Break loop once per entry
                break;
            
            string stars(population / 1000, '*'); // Count stars for each 1000
            
            cout << setw(6)  << interval_count    // Print out results
                 << setw(30) << stars
                 << endl;

            
            interval_count+=20; // Interval rate of change
        }
        
    }
    else
       cout << "Error, the file " << inFileName << " was not found.\n"; // QUIT PROGRAM
    
    return 0;
}
/*  TEST OUTPUT

The file people.txt was successfully opened.                                                                                                                                            

PRAIRIEVILLE POPULATION GROWTH                                                                                                                                                          
(each * represents 1000 people)                                                                                                                                                         

YEAR  POPULATION                                                                                                                                                                        
1910  **                                                                                                                                                                                
1930  ****                                                                                                                                                                              
1950  *****                                                                                                                                                                             
1970  *********                                                                                                                                                                         
1990  **************                                                                                                                                                                    
2010  ******************                                                                                                                                                                
2030  ******************************                                                                                                                                                    
2050  *********                                                                                                                                                                         
2070  **                                                                                                                                                                                
2090  ****                                                                                                                                                                              
2110  *                                                                                                                                                                                 


Process exited with code: 0
*/