/* CS1136- Lab Lesson 6 (Part 2 of 2)
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : October 20, 2019
*/

//header files
#include <iostream>
#include<iomanip>

using namespace std;

//this program converts degrees Fahrenheit to celsius and kelvin besed on the input range and increment
int main()
{
    //variables
    double min;
    double max;
    double increment;
    double celsius;
    double kelvin;
    
    int x =1;
    
    //used to keep track of loop
    while(x>0)
    {
        cin >> min >> max >> increment;
        
        if(min <= max && increment > 0)
        {
            cout << setw(18) << fixed << setprecision(4)<< "Fahrenheit";
            cout << setw(18) << fixed << setprecision(4)<< "Celsius";
            cout << setw(18) << fixed << setprecision(4)<< "Kelvin" << endl;
            
            for(double i = min; i <=max; i+=increment)
            {
                celsius = (i - 32) / 1.8; // calculates celsius
                kelvin = celsius + 273.15; //calculates farenheit
                
                cout << setw(18) << fixed << setprecision(4) << i;
                cout << setw(18) << fixed << setprecision(4) << celsius;
                cout << setw(18) << fixed << setprecision(4) << kelvin << endl;
            }
            
            x =0; //exists loop
        }
        else //if values entered were incorrect
        {
            cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
        }
    }
    
    //program returns 0
    return 0;
}
