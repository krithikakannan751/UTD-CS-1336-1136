/*
   CS1136 - lesson7part2
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : October 27, 2019
*/

//Headrer files
#include<iostream> //fpr cin/cout
#include<fstream> //for ifstream/ ofstream
#include<iomanip> //for fixed/left/set precision

using namespace std;

/*
 This program calculates the valid invalid, and total numbers from a text 
 file and then calulates the average from the valid numbers from the list
*/
int main()
{
	//Variables
	double input; //stores values from the file
	double average; //stores calculated average of the valid numbers 
	double total = 0; //stores the sum of the valid numbers from the text file
	int numbers = 0; //stores the total numbers form the text file
	int invalid = 0; //stores the total invalid numbers from the text file
	int valid = 0; //stores the total valid numbers from the text file
	string fileName; //stores the filename the user enters
	
	ifstream inputFile; //declares the input file
	ofstream outputFile; //declares the output file

	//User enters file name
	cout << "Enter input file name" << endl;
	cin >> fileName;
	inputFile.open(fileName); //opens file user enters

	outputFile.open("invalid-values.txt"); //opens output file

	//checks to see if input file can be opened 
	if(inputFile) 
	{
		//checks to see if output file can be opened
		if (outputFile)
		{
			while (inputFile >> input) //loops through all valued from the file
			{
				numbers++;//increments numbers as new input is encountered
				if (input >= 0 && input <= 105)//checks to see if input is within range
				{
					valid++;//incraments valid if input is within range
					total += input; //adds input to total
				}
				else
				{
					invalid++;
					outputFile << left << fixed << setprecision(5) << input << "\n";
				}
			}

			//Display
			cout << "Reading from file \"" << fileName << "\"" << endl; //file name
			cout << "Total values: " << numbers << endl; //total values
			cout << "Invalid values: " << invalid << endl; //invalid numbers
			cout << "Valid values: " << valid << endl; //valid numbers

			//checks to see if valid is not equal to 0
			if (valid != 0)
			{
				average = total / valid; //calculates average of valid values
				cout << "Average of valid values: " << fixed << setprecision(4) << average << endl;
			}
			else //if valid is equal to 0
			{
				cout << "An average cannot be calculated" << endl;
			}
			outputFile.close();//closes output file
		}
		inputFile.close(); //closes input file
	}
	else //if inputfile is not true
	{
		cout << "File \""<< fileName << "\" could not be opened" << endl;
		inputFile.close(); //closes inputfile
	}

	//program returns 0
	return 0;
}