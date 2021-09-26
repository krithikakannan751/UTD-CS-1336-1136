/* CS1336 - Homework #6
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : September 23, 2019
*/

//Header files
#include <iostream> //For cin/cout
#include <cmath> //For abs

using namespace std;

//This program displays a square or triangle based on the input
int main()
{
    //Variables
    int input = 1;
   
    while(input >= -20 && input <= 20 && input != 0) //Checks to see if input is within range
    {
        //Input an integer
        cout << "Enter a integer value from [-20,20] or enter 0 to quit: " << endl;
        cin >> input;
        
        //Checks to see if program should quit
        if(input != 0)
        {
            if(input < 0 && input >= -20) //Checks to see if input is negative and within range
            {
                cout << endl;
                
                //Prints out a triangle
                for(int i = 0; i < abs(input); i++)
                {
                    for(int j = 0; j < i; j++)
                    {
                        cout << "x";
                    }
                    
                    cout << "x" << endl;
                }
                
                cout << endl;
            }
            
            else if(input > 0 && input <= 20) //Checks to see if input is positive and within range
            {
                cout << endl; 
                
                //Prints out a square
                for(int i = 0; i < input; i ++)
                {
                    for(int j = 1; j < input; j++)
                    {
                        cout << "x";
                    }
                    
                    cout << "x" << endl;
                }
                
                cout << endl;
            }
            
            else //Resets input if it isn't within range
            {
                input = 1;
                cout << endl;
                cout << "Input is not within range!" << endl;
                cout << endl;
            }
        }
        
        else //Program quits because 0 is entered
        {
            cout << endl;
            cout << "Value entered was 0. Program will end." << endl;
            break;
        }
    }
    
    //Returns 0
    return 0;
}
