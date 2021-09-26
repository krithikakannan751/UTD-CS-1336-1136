/* CS1336 - Homework #3
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : September 8, 2019
*/

//Header Files
#include <iostream> //For cin/cout
#include <iomanip> //For setprecision method
#include <math.h> //For ceil method

using namespace std;

//Constants
const double pi = 3.14159; //Value of pi

//This program calculated the number of pizzas needed for a party
int main()
{
    //Variables
    int numPeople;
    double diameter;
    double numSlices;
    double numPizza;
    double sliceArea = 14.125; //The area of one slice of pizza
    
    //The output of the program displays in fixed-point notation, rounded to one decimal place of precision
    cout << fixed;
    cout << setprecision(1);
    
    //To get the num of people attending the party
    cout << "How many people are at the party?" << endl;
    cin >> numPeople;
    
    //To ask the diameter of the pizza
    cout << "What is the diameter of the pizza in inches?"<< endl;
    cin >> diameter;
    
    //To calculate and display the number of sclices that can be taken from one pizza
    numSlices = (pi * (diameter/2) * (diameter/2)) / sliceArea;
    cout << "Number of slices that can be taken: " << numSlices << endl;
    
    /*To calculate and display the number of pizzas needed if each person attending 
      is expected to eat an average of four slices
    */
    numPizza = ceil((4 * sliceArea * numPeople) / (pi * (diameter/2) * (diameter/2)));
    cout << "Number of pizzas needed if each person attending is expected to eat an average of four slices : " << numPizza << endl;
    
    //The return for this method is 0
    return 0;
}
