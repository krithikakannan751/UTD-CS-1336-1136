/* Krithika Kannan
   1136.102 
   Lab Lesson 4 Part 1
   9/28/2019
*/

//Header files
#include <iostream>
#include <iomanip>

using namespace std;

//Constants
const double EarthGravity = 9.81;
const double MoonGravity = 1.62;
const double VenusGravity = 8.87;

/* This program reads the mass of an object (in kg) and output the weight 
   (in N) on the Earth, on the Moon, and on Venus.
*/
int main()
{ 
    //Variables
    double mass;
    
    //User inputs mass
    cout << "Enter the mass in kg" << endl;
    cin >> mass;
    
    //Checks to see if mass is within range
    if(mass > 0)
    {
        //Outputs table header
        cout << "The mass is " << fixed << setprecision(4) << mass << " kg" << endl;
        cout << left << setw(8) << "Location" ;
        cout << right << setw(14) << "Weight (N)" << endl;
        
        //Outputs calculations for Earth
        cout << left << setw(8) << "Earth" ;
        cout << right << setw(14) << mass * EarthGravity << endl;
        
        //Outputs calculations for the Moon
        cout << left << setw(8) << "Moon" ;
        cout << right << setw(14) << mass * MoonGravity << endl;
        
        //Outputs calculations for Venus
        cout << left << setw(8) << "Venus" ;
        cout << right << setw(14) << mass * VenusGravity << endl;
        
        //Checks is object is heavy
        if(mass * EarthGravity >= 1500)
        {
            cout << "The object is heavy" << endl;
        }
        if(mass * EarthGravity < 5)
        {
            cout << "The object is light" << endl;
        }
    }
    else
    {
        cout << "The mass is " << fixed << setprecision(4) << mass << " kg" << endl;
        cout << "The mass must be greater than zero" << endl;
    }
    
    
    //Returns 0
    return 0;
}
