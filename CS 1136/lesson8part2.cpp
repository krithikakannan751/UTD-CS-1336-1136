/* Krithika Kannan
   1136.102 
   Lab Lesson 8 Part 2
   11/10/2019
*/

//Header Files
#include <iostream> //For cin/cout
#include <cmath> //for pow()
#include <iomanip> // for fixed(), setprecision() 

//Prototypes
//Calculates present value
double presentValue(double futureValue, double interestRate, int numberYears);
//asks user to enter future value
double futureValue();
//asks user to enter interest rate
double interestRate();
//asks user to enter the number of years 
int numberYears();
//Displays presentValue, futureValue, interestRate, and numberYears
void display();

using namespace std;

/*
  This program calculates the present value of money based on the number of years, future value, and interest rate
*/
int main()
{
    //calls the display method
    display(); 

    //returns 0
    return 0;
}

/*
  function returns the future value entered if it is greater than 0, if not, then it returns -1
*/
double futureValue()
{
    //Variables
    double futureValue; //stores future value

    //Prompts user to enyter future value
    cout<<"Enter future value" << endl;
    cin >> futureValue;

    //Checks to see if future value is greater than 0
    if(futureValue <= 0)//if it not greater than 0, then return -1
    {
        cout << "The future value must be greater than zero" << endl;
        return -1; //returns -1
    }
    else //if greater than 0, return value entered
    {
        return futureValue; //returns futureValue
    }
}

/*
   function returns interest rate entered if it is greater than 0, if not, it returns -1
*/
double interestRate()
{
    //Variables
    double interestRate; //stores interest rate entered

    //Prompts user to enter interest rate
    cout<<"Enter annual interest rate" << endl;
    cin >> interestRate;

    //Checks to see if interest rate is above 0
    if(interestRate<=0) //if it is lessthan 0, then return -1
    {
        cout << "The annual interest rate must be greater than zero" << endl;
        return -1; //returns -1
    }
    else //if it is greater than 0, then return annual interest rate
    {
        return interestRate*0.01; // to return interest rate in decimal form, interest rate is multiplied by 0.01
    }
}

/*
   function returns number of years entered if it is greater than 0, if not, it returns -1
*/
int numberYears()
{
    //Variables
    int numberYears; //stores entered numberYears

    //Prompts user to enter years
    cout<<"Enter number of years" << endl;
    cin >> numberYears;

    //If number of years is greater than 0, then return what was entered, else reyurn -1
    if(numberYears<=0) //if numberYears is less than or equal to 0
    {
        cout << "The number of years must be greater than zero" << endl;
        return -1; //returns -1
    }
    else //if numberYears is greater than 0
    {
        return numberYears; //returns numberYears
    }
}

/*
   function calculated presentValue with the equation P = F / ( (1 + r) ^ n)
*/
double presentValue(double futureValue, double interestRate, int numberYears)
{
    //Calculation
    double presentValue = futureValue / (pow((1+interestRate),numberYears));

    return presentValue;//Retyurns present value
}

/*  
   Function displays prestent value, future value, interest rate, and number of years
*/
void display()
{
    //Variables
    double fValue; //stores future value
    double iRate; //stores interest rate
    int Years; //stores number of years
    double pValue; //stores present value

    //Variables to control loop
    int x =1; //loop ends if x =0
    int y =1; //loop ends if y =0
    int z =1; //loop ends if z =0
    
    //while loop to keep asking user to enter fValue, iRate, Years until they are greater than 0
    while(x!=0) //asks user to enter futureValue until greater than 0
    {
        //Stores return value of future value method into fValue
        fValue = futureValue();

        //Checks to see if fValue if greater than 0
        if(fValue > 0)
        {
            //while loop asks user to enter interestRate until greater than 0
            while(y!=0)
            {
                //stores return value of interest rate method into iRate
                iRate = interestRate();

                //Checks to see if iRate is greater than 0
                if(iRate > 0)
                {
                    //while loop asks user to enter number Years until greater than 0
                    while(z!=0)
                    {
                        //stores return value of numberYears into Years
                        Years = numberYears();

                        //Checks to see if Years is greater than 0
                        if(Years >0)
                        {
                            //loop Variables are set to 0 to end loops
                            x=0;
                            y=0;
                            z=0;

                            //Calculates present value and stores it inot pValue
                            pValue = presentValue(fValue, iRate, Years);

                            //Displays pValue, fValue, iRate, and Years
                            cout << "Present value: $" <<  fixed << setprecision(2) << pValue << endl;
                            cout << "Future value: $" << fixed << setprecision(2) << fValue << endl;
                            cout << "Annual interest rate: " << fixed << setprecision(3) << iRate *100 << "%" << endl;
                            cout << "Years: " <<  Years << endl;
                        }
                    }
                }
            }
        }
    }
}