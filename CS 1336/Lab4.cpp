/* CS1336 - Homework #4
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : September 15, 2019
*/

//Header files
#include <iostream> //For cin/cout

using namespace std;

//This program displays the min and max from a set of 3 numbers
int main()
{
    //Variables
    double num1;
    double num2;
    double num3;
    double min;
    double max;
    
    //Input of the three values
    cout << "Enter number 1: " << endl;
    cin >> num1;
    cout << "Enter number 2: " << endl;
    cin >> num2;
    cout << "Enter number 3: " << endl;
    cin >> num3;
    
    //Calculates the min value
    if(num1 < num2 && num1 < num3)
    {
        min = num1;
    }
    else if(num2 < num3 && num2 < num1)
    {
        min = num2;
    }
    else
    {
        min = num3;
    }
    
    //Calculates the max value
    if(num1 > num2 && num1 > num3)
    {
        max = num1;
    }
    else if(num2 > num3 && num2 > num1)
    {
        max = num2;
    }
    else
    {
        max = num3;
    }
    
    //Displays the min and max values
    cout << "Min Value: " << min << endl;
    cout << "Max Value: " << max << endl;
    
    //Returns 0
    return 0;
}
