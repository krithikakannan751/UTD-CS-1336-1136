/*
    Krithika Kannan
    CS 1136.102
    lesson 9 part 1
    17 November 2019
*/

//Header files
#include <iostream> //for cin/cout
#include <iomanip> // for fixed, setw, setprecision

using namespace std;

//prototypes
void read(int&, int&, char&, double&); //to read in spoolsOrdered, spoolStock, shippingHandling, shippingAmount
void display(int&, int&, double&); //to display charges

//This program manages the shipping info for Acme Wholesale Copper Wire Company
int main()
{
    //variables
    int spoolsOrdered;
    int spoolStock;
    char shippingHandling;
    double shippingAmount;
    
    //call to read and display methods
    read(spoolsOrdered, spoolStock, shippingHandling, shippingAmount);
    display(spoolsOrdered, spoolStock, shippingAmount);
    
    //program returns 0
    return 0;
}

//function reads in entered values
void read(int& spoolsOrdered, int& spoolStock, char& shippingHandling, double& shippingAmount)
{
    //variables
    int x =1; //controls while loop
    
    while(x!= 0)
    {
        cout << "Spools to be ordered" << endl;
        cin >> spoolsOrdered;
        if(spoolsOrdered <1)
        {
            cout << "Spools order must be 1 or more" << endl;
        }
        else
        {
            while(x !=0)
            {
                cout << "Spools in stock" << endl;
                cin >> spoolStock;
                if(spoolStock <0)
                {
                    cout << "Spools in stock must be 0 or more" << endl;
                }
                else
                {
                    cout << "Special shipping and handling (y or n)" << endl;
                    cin >> shippingHandling;
                    if(shippingHandling == 'y')
                    {
                        while(x !=0)
                        {
                            cout << "Shipping and handling amount" << endl;
                            cin >> shippingAmount;
                            if(shippingAmount<0)
                            {
                                cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
                            }
                            else
                            {
                                x =0;
                            }
                        }
                    }
                    else if(shippingHandling == 'n')
                    {
                        shippingAmount = 12.99;
                        x=0;
                    }
                }
            }
        }
    }
}


//function displays info about shipping
void display(int& spoolsOrdered, int& spoolStock, double& shippingAmount)
{
    //variables
    double copperWire = 104;
    int ship;
    int backOrder;
    
    if(spoolsOrdered >= spoolStock)
    {
        ship = spoolStock;
        backOrder = spoolsOrdered -spoolStock;
    }
    else
    {
        ship = spoolsOrdered;
        backOrder =0;
    }
    
    //Display
    cout << "Spools ready to ship: " << ship << endl;
    cout << "Spools on back-order: " << backOrder << endl;
    cout << "Subtotal ready to ship: $" << setw(10) << fixed << setprecision(2) << ship * copperWire << endl;
    cout << "Shipping and handling:  $" << setw(10) << fixed << setprecision(2) << spoolStock * shippingAmount << endl;
    cout << "Total shipping charges: $" << setw(10) << fixed << setprecision(2) << ship * copperWire + spoolStock * shippingAmount <<  endl;
}
