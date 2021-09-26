/* CS1336 - Homework #2
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : August 31, 2019
*/

#include <iostream>
#include<iomanip> //needed for the setPrecision method
using namespace std;

/* Program used to calculate he amount of income per ticket type,
   the amount of income generated from total ticket sales,
   andthe average income per ticket
*/
int main()
{
    //Variables to store the amount of each ticket
    int classA;
    int classB;
    int classC;
    
    //Statements for setting the decimal point when returning values
    cout << fixed;
    cout << setprecision(2);
    
    //These statements are used to get the input for the number of each type of ticket
    cout << "Number of tickets sold: " << endl;
    cout << "How many Class A tickets were sold?" << endl;
    cin >> classA;
    cout << "How many Class B tickets were sold?" << endl;
    cin >> classB;
    cout << "How many Class C tickets were sold?" << endl;
    cin >> classC;
    
    //These statements are used to display the income for each type of ticket
    cout << endl;
    cout << "Income for each type of ticket: " << endl;
    cout << "Income for Class A tickets: $" << classA * 13.00 << endl; 
    cout << "Income for Class B tickets: $" << classB * 11.00 << endl; 
    cout << "Income for Class C tickets: $" << classC * 7.00 << endl; 
    
    //These statements are used to display the total ticket sale
    cout << endl;
    cout << "Amount of income generated from total ticket sale: $" 
         << (classA*13.00) + (classB*11.00) + (classC*7.00) << endl;
    
    //These statements are used to display the average income per ticket
    cout << endl;
    cout << "The average income per ticket: $" 
         << ((classA*13.00) + (classB*11.00) + (classC*7.00))/(classA + classB + classC) 
         << endl;

    //The return is 0 for this method
    return 0;
}
