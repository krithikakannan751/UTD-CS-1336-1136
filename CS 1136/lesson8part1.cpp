/* Krithika Kannan
   1136.102 
   Lab Lesson 8 Part 1
   11/10/2019
*/

//Header Files
#include <iostream> //For cin/cout
#include <cmath> //for pow()
#include <iomanip> // for fixed(), setprecision(), 

//Prototypes
//To read in the number of seconds user enters
double readSeconds();
//Calculate the distance an object falls (on Earth) during the specified number of seconds
double calculateEarthDistance(double seconds);
//Calculate the distance an object falls (on the Moon) during the specified number of seconds
double calculateMoonDistance(double seconds); 
//Display the number of seconds an object has fallen as well as the distance the object has fallen on the Earth and on the Moon.
void displayResults(double seconds, double earthDistance, double moonDistance);

using namespace std;

/*
  Calculates the distance an object travels (in meters) on Earth for a specified number of seconds, 
  also calculates the distance traveled on the Moon (in meters) for the specified number of seconds
*/
int main()
{
    //Variables
    int x = 1; //Used to keeep track of the while loop
    double earthDistance; //Stores calculated earth distance
    double moonDistance; //Stores calculated moon distance
    double seconds; //Stores seconds user inputs
    
    //While loop keeps looping until the number 0 is entered 
    while(x!=0)
    {
        //stores seconds from the readSeconds() method
        seconds = readSeconds();
        
        //if seconds is equal to 0, then end the loop
        if(seconds==0.0)
        {
            x = 0;
        }
        else //if seconds is not equal to 0, then calculate earthDistance and moonDiatance and displayResults
        {
            //Only calculate results if seconds is greater than 0
            if(seconds > 0.0) 
            {
               earthDistance = calculateEarthDistance(seconds); //stores calculated earth distances into the earthdistance method
               moonDistance = calculateMoonDistance(seconds); //stores calculated moon distance into moon distance method
               
               displayResults(seconds, earthDistance, moonDistance); //displays results
            }
        }
    }
    //methot returns 0
    return 0;
}

/*
  This function reads in seconds and returns the number if it is greater than 0. If seconds is less than 0, the function returns -1
*/
double readSeconds()
{
    //Variable
    double seconds; //Stores input seconds

    //Prompts user to enter seconds and stores the value
    cout<<"Enter the time (in seconds)" << endl;
    cin >> seconds;

    //Checks to see if seconds is greater than 0
    if(seconds<0.0) //if less than 0, return -1
    {
        cout << "The time must be zero or more" << endl;
        return -1;
    }
    else //else reyurn value inputed
    {
        return seconds;
    }
}

/*
  function will calculate the distance an object falls (on Earth) during the specified number of seconds
*/
double calculateEarthDistance(double seconds)
{
    //Variables
    double earthGravitationalField = 9.8; //Earth's gravitational field is 9.8

    //Calculation
    double earthDistance = 0.5 * earthGravitationalField * pow(seconds,2); //equation to find distance

    //Retuns earth distance
    return earthDistance;
}

/*
  function will calculate the distance an object falls (on the Moon) during the specified number of seconds
*/
double calculateMoonDistance(double seconds)
{
    //Variables
    double moonGravitationalField = 1.6; //Moon's gravitational field is 1.6

    //Calculation
    double moonDistance = 0.5 * moonGravitationalField * pow(seconds,2); //Equation to find distance

    //Returns moon distance
    return moonDistance;
}

/*
   function that will display the number of seconds an object has fallen as well as the 
   distance the object has fallen on the Earth and on the Moon.
*/
void displayResults(double seconds, double earthDistance, double moonDistance)
{
    //Prints out earth distance
    cout << "The object traveled " << fixed << setprecision(4) << earthDistance << " meters in "
         << fixed << setprecision(2) << seconds << " seconds on Earth" << endl;
    
    //Prints out moon distance
    cout << "The object traveled " << fixed << setprecision(4) << moonDistance << " meters in " 
         << fixed << setprecision(2) << seconds << " seconds on the Moon" << endl;
}