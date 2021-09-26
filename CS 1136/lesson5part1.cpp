/*
Krithika Kannan
1336.102
Lab Lesson 5 (Part 1 of 2)
10/12/19
*/

//Header files
#include <iostream>
#include <iomanip>

using namespace std;

//This program calculates the number of seconds it will take for sound to travel though a medium
int main()
{
    //Variables 
    unsigned int menuInput; //number selected from menu
    double distance; //distance value entered
    
    //Displays menu and gets user selection
    cout << "Select the medium that sound is traveling through:"<<endl;
    cout << "1 Air" << endl;
    cout << "2 Water" << endl;
    cout << "3 Steel" << endl;
    cin >> menuInput;
    
    //Calculates the rate at which sound travels through the medium the user selected
    switch(menuInput)
    {
    case 1: //for air
        cout << "Enter distance (in feet)" << endl; //prompts user to enter distance
        cin >> distance; 
        if(distance > 0)
        {
            cout << "Air: " << fixed << setprecision(4) << distance << " ft" << endl;
            //1100 is Speed (feet per second) for air
            cout << "Traveled for " << fixed << setprecision(4) << distance/1100 << " seconds" << endl; 
        }
        else
            cout << "The distance must be greater than zero" << endl;
        
        break;
    case 2: //for water
        cout << "Enter distance (in feet)" << endl; //prompts user to enter distance
        cin >> distance;
        if(distance > 0)
        {
            cout << "Water: " << fixed << setprecision(4) << distance << " ft" << endl;
            //4900 is Speed (feet per second) for water
            cout << "Traveled for " << fixed << setprecision(4) << distance/4900 << " seconds" << endl;
        }
        else
            cout << "The distance must be greater than zero" << endl;
        
        break;
    case 3: //for steel
        cout << "Enter distance (in feet)" << endl; //prompts user to enter distance
        cin >> distance;
        if(distance > 0)
        {
            cout << "Steel: " << fixed << setprecision(4) << distance << " ft" << endl;
            //16400 is Speed (feet per second) for steel
            cout << "Traveled for " << fixed << setprecision(4) << distance/ 16400 << " seconds" << endl;
        }
        else
            cout << "The distance must be greater than zero" << endl;
        
        break;
    default: //when user inputs the wrong value
        cout << "The menu value is invalid. Please run the program again."<< endl;
        break;
    }
    //program returns 0
    return 0;
}
