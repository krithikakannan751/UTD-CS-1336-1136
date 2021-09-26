/* Krithika Kannan
   1136.102 
   Lab Lesson 4 Part 2
   9/28/2019
*/

//Header files
#include <iostream>
#include <iomanip>

using namespace std;

/* This program reads in the number of seconds and converts it to days, 
   hours, minutes and remaining seconds
*/
int main()
{ 
    //Variables
    long long int seconds;
    
    //User inputs seconds
    cout << "Enter seconds" << endl;
    cin >> seconds;
    cout << "Total seconds: " << seconds << endl;
    
    //Checks to see seconds is greater than 0
    if(seconds > 0)
    {
        cout << endl;
        
        //Outputs days
        if(seconds/86400 > 0) //86400 is the number of seconds in a day
        {
            cout << seconds/86400 << " day(s)" << endl;
        }
        
        //Outputs hours
        if(seconds % 86400 / 3600 > 0) //3600 is the number of seconds in an hour
        {
            cout << seconds % 86400 /3600 << " hour(s)" << endl;
        }
        
        //Outputs minutes
        if(seconds % 86400 % 3600 / 60 > 0) //60 is the number of seconds in a minute
        {
            cout << seconds % 86400 % 3600 / 60 << " minute(s)" << endl;
        }
        
        //outputs seconds
        if(seconds % 86400 % 3600 % 60 > 0)
        {
            cout << seconds % 86400 % 3600 % 60 << " second(s)" << endl; 
        }
    }
    else
    {
        cout << endl;
        cout << "Total seconds must be greater than zero" << endl;
    }
    
    //Returns 0
    return 0;
}
