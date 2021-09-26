/*
Krithika Kannan
1336.102
Lab Lesson 5 (Part 2 of 2)
10/12/19
*/

//Header files
#include <iostream>
#include <iomanip>

using namespace std;

//Prototypes
double calculation(double, double);
bool checkRange(double);

//This program calculates the number of meters sound will to travel though a medium, given seconds
int main()
{
    //Variables 
    unsigned int input;
    double seconds;
    
    //Menu and user input
    cout << "Select the medium that sound is traveling through:" << endl;
    cout << "1 Carbon Dioxide" << endl;
    cout << "2 Air" << endl;
    cout << "3 Helium" << endl;
    cout << "4 Hydrogen" << endl;
    cin >> input;
    
    
    if(input ==1) //for carbon dioxide
    { 
        //User inputs seconds
        cout << "Enter time (in seconds)" << endl;
        cin >> seconds;
        
        if(checkRange(seconds))
        {
            cout << "Carbon Dioxide: " << fixed << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << fixed << setprecision(4) << calculation(seconds, 258.0)  << " meters"<< endl;
        }
        else
        {
            cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
        }
    }
    else if (input ==2) //for air
    {
        //User inputs seconds
        cout << "Enter time (in seconds)" << endl;
        cin >> seconds;
        
        if(checkRange(seconds))
        {
            cout << "Air: " << fixed << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << fixed << setprecision(4) << calculation(seconds, 331.5)  << " meters"<< endl;
        }
        else
        {
            cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
        }
    }
    else if (input ==3) //for helium
    {
        //User inputs seconds
        cout << "Enter time (in seconds)" << endl;
        cin >> seconds;
            
        if(checkRange(seconds))
        {
            cout << "Helium: " << fixed << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << fixed << setprecision(4) << calculation(seconds, 972.0)  << " meters"<< endl;
        }
        else
        {
            cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
        }
    }
    else if (input ==4) //for hydrogen
    {
        //User inputs seconds
        cout << "Enter time (in seconds)" << endl;
        cin >> seconds;
            
        if(checkRange(seconds))
        {
            cout << "Hydrogen: " << fixed << setprecision(3) << seconds << " seconds" << endl;
            cout << "Traveled " << fixed << setprecision(4) << calculation(seconds, 1270.0)  << " meters"<< endl;
        }
        else
        {
            cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
        }
    }
    else //if user does not input 1, 2, 3, or 4
    {
        cout << "The menu value is invalid. Please run the program again." << endl;
    }
    
    
    //program returns 0
    return 0;
}

//This method calculates the distance
double calculation(double seconds, double speed)
{
    return seconds*speed;
}

//This method checks to see if the number of seconds entered was within range
bool checkRange(double seconds)
{
    if(seconds >= 0.000 && seconds <= 30.000)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
