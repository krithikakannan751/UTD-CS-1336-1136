/* CS1336 - Homework #5
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : September 22, 2019
*/

//Header files
#include <iostream> //For cin/cout

using namespace std;

/*This program asks for a temperature in degrees Fahrenheit, 
  then calculates if the following substances, water, lead, 
  alcohol, nitrogen, mercury, chlorine, would be solid, liquid, 
  or gas at that temperature.
*/
int main()
{
    //Variables
    double temperature;
    
    //Asking for temperature in Fahrenheit
    cout << "Input a temperature in degrees Fahrenheit (between -459.67 and 3000): " << endl;
    cin >> temperature;
    
    //Checks to see if temperature is within range
    if(temperature <= 3000 && temperature >= -459.67) //Range is between -459.67 and 3000
    {
        cout << "At " << temperature << " degrees Fahrenheit: " << endl;
        
        //Calculation for water
        if(temperature <= 32) //32 is the melting point of water
        {
            cout << "\tWater is a solid." << endl;
        }
        else if(temperature > 212) //212 is the boiling point of water
        {
            cout << "\tWater is a gas." << endl;
        }
        else
        {
            cout << "\tWater is a liquid." << endl;
        }
        
        //Calculation for lead
        if(temperature <= 621.5) //621.5 is the melting point of lead
        {
            cout << "\tLead is a solid." << endl;
        }
        else if(temperature > 3180) //3180 is the boiling point of lead
        {
            cout << "\tLead is a gas." << endl;
        }
        else
        {
            cout << "\tLead is a liquid." << endl;
        }
        
        //Calculation for alcohol(ethanol)
        if(temperature <= -173.5) //-173.5 is the melting point of alcohol
        {
            cout << "\tAlcohol is a solid." << endl;
        }
        else if(temperature > 173.1) //173.1 is the boiling point of alcohol
        {
            cout << "\tAlcohol is a gas." << endl;
        }
        else
        {
            cout << "\tAlcohol is a liquid." << endl;
        }
        
        //Calculation for nitrogen
        if(temperature <= -346) //-346 is the melting point of nitrogen
        {
            cout << "\tNitrogen is a solid." << endl;
        }
        else if(temperature > -320.4) //-320.4 is the boiling point of nitrogen
        {
            cout << "\tNitrogen is a gas." << endl;
        }
        else
        {
            cout << "\tNitrogen is a liquid." << endl;
        }
        
        //Calculation for mercury 
        if(temperature <= -37.89) //-37.89 is the melting point of mercury
        {
            cout << "\tMercury is a solid." << endl;
        }
        else if(temperature > 674.1) //674.1 is the boiling point of mercury
        {
            cout << "\tMercury is a gas." << endl;
        }
        else
        {
            cout << "\tMercury is a liquid." << endl;
        }
        
        //Calculation for chlorine
        if(temperature <= -150.7) //-150.7 is the melting point of chlorine
        {
            cout << "\tChlorine is a solid." << endl;
        }
        else if(temperature > -29.27) //-29.27 is the boiling point of chlorine
        {
            cout << "\tChlorine is a gas." << endl;
        }
        else
        {
            cout << "\tChlorine is a liquid." << endl;
        }
    
    }
    else 
    {
        cout << "Error! Value entered was not between -459.67 and 3000 Farenheit." << endl;
    }
    
    //Returns 0
    return 0;
}