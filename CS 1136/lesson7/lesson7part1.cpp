/*
   CS1136 - lesson7part1
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : October 27, 2019
*/

//header files
#include<iostream> //used for cin/cout
#include<fstream> //used for ifstream/ofstream
#include<iomanip> //used for setw

using namespace std;

/*
  This program reads in a file with a list of storeNumbers and storeValues and 
  creates a bar graph with the corresponding values onto a text file
*/
int main() 
{
	//Variables
	unsigned int storeNumber; //stores store number from file
	long long int salesValue; //stores sales value from file

	ifstream inputFile; //Declares inputFile
	ofstream outputFile; //Declares outputfile
	
	string fileName; //Stores the filename that the user enters
	
	long long int asterisks; //calculates and stores the number of asterisks on the graph

	//User enters a file name
	cout << "Enter input file name" << endl;
	cin >> fileName;
	inputFile.open(fileName); //opens file user enters

	outputFile.open("saleschart.txt"); //opens saleschart text file

	//Checks to see if input and output file exists
	if (inputFile) //checks to see if input file exists
	{
		if (outputFile) //checks to see if output file exists
		{
			//Displays the title and the key of the bar chart
			outputFile << "SALES BAR CHART\n(Each * equals 5,000 dollars)\n";

			//Reads in the storeNumber and storValue from the inputFile
			while (inputFile >> storeNumber >> salesValue)
			{
				if (storeNumber >= 1 && storeNumber <= 99) //checks to see if the storeNumber is within range
				{
					if (salesValue >= 0) //cheacks to see if the salesValue is within range
					{
						outputFile << "Store" << setw(3) << right << storeNumber << ": "; //Displays the left side of the graph
						asterisks = salesValue / (long long int)5000; //calculates the number of asterisks needed
						
						//Displays asterisks
						for (int i = 0; i < asterisks; i++)
						{
							outputFile << "*";
						}
						outputFile << "\n"; //moves to a new line aster each store
					}
					else //if sales value isn't within range
					{
						cout << "The sales value for store " << storeNumber << " is negative" << endl;
					}
				}
				else //if store number isn't within range
				{
					cout << "The store number " << storeNumber << " is not valid" << endl;
				}
			}
		 outputFile.close(); //close output file
		}
		else //if output file does not exist
		{
			cout << "The file could not be opened" << endl;
			outputFile.close(); //close output file
		}
	 inputFile.close(); //close input file
	}
	else //if input file does not exist
	{
		cout << "File \"" << fileName << "\" could not be opened" << endl;
		inputFile.close(); //close input file
	}
   //Program returns 0
   return 0;
}