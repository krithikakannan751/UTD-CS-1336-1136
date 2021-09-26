/*
    Krithika Kannan
    CS 1136.102
    lesson 9 part 2
    17 November 2019
*/

//Header files
#include <iostream> //for cin/cout
#include <cmath> //for pow()
#include <iomanip> // for setprecision/ fixed
#include <fstream> //for ifstream/ofstream

using namespace std;

//Prototypes
double futureValue(double& presentValue, double& interestRate, int& months);
void display(ofstream& outputFile, double& futureValue, double& presentValue, double& interestRate, int& months);
unsigned int read(ifstream& inputFile, double& presentValue, double& interestRate, int& months);

//This program calculates the future value of money given presentValue, in, and number of months
int main()
{   //file variables 
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    
    //calculation variables
    double presentValue;
    double interestRate;
    int months;
    double FutureValue;
    
    //opens file
    cout << "Enter input file name" << endl;
	cin >> fileName;
	inputFile.open(fileName);
	
	outputFile.open("output.xls");
	
	if(inputFile)
	{
	    if(outputFile)
	    {
	        outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;
	        while(!inputFile.eof())
	        {
	           if(read(inputFile, presentValue, interestRate, months) == 1)
	           {
	               interestRate /= 100;
	               FutureValue = futureValue(presentValue, interestRate, months);
	               display(outputFile, FutureValue, presentValue, interestRate, months);
	           }
	           else if(read(inputFile, presentValue, interestRate, months) == 2)
	           {
	               
	           }
	           else
	           {
	                break;
	           }
	       
	        }
	        outputFile.close();
	    }
	    else
	    {
	        cout << "The file could not be opened" << endl;
			outputFile.close(); 
	    }
	    inputFile.close();
	}
	else
	{
	    cout << "File \"" << fileName << "\" could not be opened" << endl;
		inputFile.close(); 
	}
    return 0;
}

//Displays info onto a file
void display(ofstream& outputFile, double& futureValue, double& presentValue, double& interestRate, int& months)
{
    outputFile << fixed << setprecision(2) << futureValue << "\t" << fixed 
               << setprecision(2) << presentValue << "\t" << fixed << setprecision(3) << interestRate*100
               << "\t" << months << endl;
}

//calculates future value
double futureValue(double& presentValue, double& interestRate, int& months)
{
    double futureValue;
    futureValue = presentValue * pow((1 + interestRate),months);
    return futureValue;
}

//reads in info from a file
unsigned int read(ifstream& inputFile, double& presentValue, double& interestRate, int& month)
{
    if(inputFile >> presentValue >> interestRate >> month)
    {
        if(presentValue > 0 && interestRate > 0 && month > 0)
        {
            return 1;
        }
        else
        {
            cout << fixed << setprecision(2) << presentValue << " " 
                 << fixed << setprecision(3) << interestRate << " " 
                 <<fixed << setprecision(2) << month << endl;
                 
            cout << "One or more of the above values are not greater than zero" << endl;
            return 2;
        }
    }
    else
    {
        return 0;
    }
}