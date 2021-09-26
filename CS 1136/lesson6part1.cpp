/* CS1136- Lab Lesson 6 (Part 1 of 2)
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : October 20, 2019
*/

//header files
#include <iostream>

using namespace std;

//This program converts integers into ASCII values based on the input range
int main()
{
    //Variables
    unsigned int upperValue; //stores upper value
    unsigned int lowerValue; //stores lower value
    char display; //stores converted int
    
    int y =1; //used for while loop
    int count = 0; //used for for loop
    
    while(y >0) //keeps track of when to stop asking user to enter a range
    {
        //asks user to enter a range
       cout << "Enter lower and upper values" << endl;
       cin >> lowerValue >> upperValue;
    
        //checks to see if range enytered is correct
       if(lowerValue<=upperValue && upperValue>=32 && upperValue<=126 && lowerValue >=32 && lowerValue<=126)
       {
           cout << "Characters for ASCII values between " << lowerValue << " and " << upperValue<< endl;
           cout << "----+----+----+----+" << endl;
           
           //prints out ascii values
           for(unsigned int i = lowerValue; i <= upperValue; i++)
           {
              display = static_cast<char>(i);
              count += 1;
              if(count ==21)//values continue on the next line after 20 characters
              {
                  cout << "\n";
                  count = 1;
              }
              cout << display;
           }
           cout<< endl;
           cout << "----+----+----+----+" << endl;
           y =0;//ends the loop
       }
       else //if wrong range entered
       {
           cout << "Values must be in range 32 to 126 inclusive" << endl;
       }
    }
    //this program returns 0
    return 0;
}