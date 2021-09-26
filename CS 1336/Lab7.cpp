/* CS1336 - Homework #7
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : October 17, 2019
*/

//Header files
#include <iostream> //for cin/cout
#include <cmath> //for sin() and cos()
#include <iomanip> // for setw(), setprecision()
#include <string> //for to_string

using namespace std;

//Constants
const double PI = 3.14159265358979323846; //value for pi

//Prototypes
double sinCalculator(double); //to calculate sin
double cosCalculator(double); //to calculate cos
double tanCalculator(double); //to calculate tan
double secCalculator(double); //to calculate sec
double cscCalculator(double); //to calculate csc
double cotCalculator(double); //to calculate cot
void dash(); //to make dashed line for table
void display(double); //to diplay table

/*
    This program converts degrees to radians and displays the calculations for 
    sin, cos, tan, csc, sec, and cot for the degree entered in a tabular format
*/
int main()
{
    //Variables
    double degrees; //stores user input
    int i = 1;//variable used make the while loop run
    
    //Checks to see that the degree entered is greater than 0. if it isn't the loop stops
    while(i > 0)//checks to see if i is greater than 1
    {
        //user enters a degree value
        cout<<"Enter an angle (in degrees) or enter a negative number to quit the program: " << endl;
        cin >> degrees;
        
        //checks to see if degree entered is greater or equal to zero
        if(degrees >= 0)//checks to see degrees entered
        {
            //displays the table of calculated values
            cout << endl;
            display(degrees);
        }
        else //if degrees entered is not positive, then the loop ends
        {
            i = 0; //i is set to 0
            cout << endl;
            cout << "Program ended. Negative number entered." << endl; //message displayed when program quits
        }
    }
    return 0; //program returns 0
}

//Display

/* 
    This function displays the calculated the value of radians, sin, cos, csc, sec, 
    tan, and cot based on the value entered 
*/
void display(double degrees)
{
    //Variables
    double radians = degrees * (PI / 180.0); //converts degrees to radians
    string str;//to compare string values
    
    dash(); //creates a dashed line
    
    //Displays the degrees entered
    cout << left << setw(25) << "Degrees: " << "|";
    cout << right << setw(20) << fixed << setprecision(4) << degrees << " |" << endl;
    dash(); //creates a dashed line
    
    //Displays the radians calculated
    cout << left << setw(25) << "Radians: " << "|";
    cout << right << setw(20) << fixed << setprecision(4) << radians << " |" << endl;
    dash(); //creates a dashed line
    
    //Diaplays the calculated sin value
    cout << left << setw(25) << "Sin(radians calculated): " << "|"; //sets up the left side of the table
    str = to_string(sinCalculator(radians)); //sets sin value to a string
    if(str.substr(0,7) == "-0.0000") //checks to see if sin value is -0.0000
    {
        //if it is, then the negative sign is removed
        cout << right << setw(20) << "0.0000" << " |" << endl;
    }
    else //if it is not -0.0000, the the normal value is printed
    {
        cout << right << setw(20) << fixed << setprecision(4) << sinCalculator(radians) << " |" << endl;
    }
    dash(); //creates a dashed line
    
    //Displays the calculated cos value
    cout << left << setw(25) << "Cos(radians calculated): " << "|"; //sets up the left side of the table
    str = to_string(cosCalculator(radians)); //sets cos value to a string
    if(str.substr(0,7) == "-0.0000") //checks to see if cos value is -0.0000
    {
        //if it is, then the negative sign is removed
        cout << right << setw(20) << "0.0000" << " |" << endl;
    }
    else //if it is not -0.0000, the the normal value is printed
    {
        cout << right << setw(20) << fixed << setprecision(4) << cosCalculator(radians) << " |" << endl;
    }
    dash(); //creates a dashed line
    
    //Displays the calculated tan value
    if((cos(radians) >= -1) && (cos(radians) < -0.0001)) //makes sure the output displayed is accurate 
    {
        cout << left << setw(25) << "Tan(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(tanCalculator(radians)); //sets tan value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if tan value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << tanCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else if((cos(radians) <= 1) && (cos(radians) > 0.0001)) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Tan(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(tanCalculator(radians)); //sets tan value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if tan value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << tanCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    } 
    else //displays "infinity" if the value entered is undefined
    {
        cout << left << setw(25) << "Tan(radians calculated): " << "|"; //sets the left side of the table
        cout << right << setw(20) << "Infinity" << " |" << endl;
        dash(); //creates a dashed line
    }
    
    //Displays the calculated csc value
    if((sin(radians) >= -1) && (sin(radians) < -0.0001)) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Csc(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(cscCalculator(radians)); //sets csc value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if tan value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << cscCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else if((sin(radians) <= 1) && (sin(radians) > 0.0001)) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Csc(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(cscCalculator(radians)); //sets csc value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if csc value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << cscCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else //displays "infinity" if the value entered is undefined
    {
       cout << left << setw(25) << "Csc(radians calculated): " << "|"; //sets up the left side of the table
       cout << right << setw(20) << "Infinity" << " |" << endl;
       dash(); //creates a dashed line  
    }
    
    //Displays the calculated sec value
    if((cos(radians) >= -1) && (cos(radians) < -0.0001 )) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Sec(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(secCalculator(radians)); //sets sec value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if sec value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << secCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else if((cos(radians) <= 1) && (cos(radians) > 0.0001)) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Sec(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(secCalculator(radians)); //sets sec value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if sec value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << secCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else //displays "infinity" if the value entered is undefined
    {
        cout << left << setw(25) << "Sec(radians calculated): " << "|"; //sets up the left side of the table
        cout << right << setw(20) << "Infinity" << " |" << endl;
        dash(); //creates a dashed line
    }
    
    //Displays the calculated cot value
    if((sin(radians)>= -1 )&& (sin(radians) < -0.0001)) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Cot(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(cotCalculator(radians)); //sets cot value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if cot value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << cotCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else if((sin(radians)<= 1) && (sin(radians) > 0.0001)) //makes sure the output displayed is accurate
    {
        cout << left << setw(25) << "Cot(radians calculated): " << "|"; //sets up the left side of the table
        str = to_string(cotCalculator(radians)); //sets cot value to a string
        if(str.substr(0,7) == "-0.0000") //checks to see if cot value is -0.0000
        {
        //if it is, then the negative sign is removed
            cout << right << setw(20) << "0.0000" << " |" << endl;
        }
        else //if it is not -0.0000, the the normal value is printed
        {
            cout << right << setw(20) << fixed << setprecision(4) << cotCalculator(radians) << " |" << endl;
        }
        dash(); //creates a dashed line
    }
    else //displays "infinity" if the value entered is undefined
    {
        cout << left << setw(25) << "Cot(radians calculated): " << "|"; //sets the left side of the table
        cout << right << setw(20) << "Infinity" << " |" << endl;
        dash(); //creates a dashed line
    }
}

/*
    This function displays a dashed line that is 48 characters long
*/
void dash()
{
    //Variables
    string s;
    
    //Loop to make the dasked line
    for(int i =0; i <= 47; i++)
    {
        s+="-";
    }
    
    //Display the line
   cout << s << endl;
}

//math calculators

/*
    Calculates sin based on the radian value entered
*/
double sinCalculator(double radians)
{
    return sin(radians); //returns sin of radians entered
}

/*
    Calculates cos based on the radian value entered
*/
double cosCalculator(double radians)
{
    return cos(radians); //returns cos of radians entered
}

/*
    Calculates tan based on the radian value entered
*/
double tanCalculator(double radians)
{
    return sin(radians)/cos(radians); //returns sin divided by cos of radians entered
}

/*
    Calculates csc based on the radian value entered
*/
double cscCalculator(double radians)
{
    return 1.0/sin(radians); //returns 1 divided by sin of radians entered
}

/*
    Calculates sec based on the radian value entered
*/
double secCalculator(double radians)
{
    return 1.0/cos(radians); //returns 1 divided by cos of radians entered
}

/*
    Calculates cot based on the radian value entered
*/
double cotCalculator(double radians)
{
    return cos(radians)/sin(radians); //returns cos divided by sin of the radians entered
}