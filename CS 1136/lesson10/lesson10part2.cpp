/*
	Krithiks Kanna
	CS 1136.102
	lesson 10 part 2
	27 november 2019
*/

//header files
#include<iostream> //for cin/cout
#include<fstream> //for ifstream
#include<iomanip> //for fixed/setprecision

using namespace std;

//constants
const int MAX_COLUMNS = 5; //for number of columns

//for prototypes
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName); //read file method
double average(double values[][MAX_COLUMNS], int numberRows); //average method
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows); //column average method
double smallestRowValue(double values[][MAX_COLUMNS], int numberRows); // smallest row value method

/*
	This program reads in a file of grades and calculates the average, column average, and smallest row value
*/
int main()
{
	//variables
	const int MAX_ROWS = 30; //for the max number of rows
	int rows; //to keep track of the number of rows
	double Average; //stores the average of the contents of the file

	//creates a 2d array of grades
	double grades[MAX_ROWS][MAX_COLUMNS];

	//reads in the input file name
	string inputFileName;
	cout << "Enter input file name" << endl;
	cin >> inputFileName;

	//calculates rows by calling read file method
	rows = readFile(grades, MAX_ROWS, inputFileName);

	//checks to see if file exists
	if (rows == -1) //if file exists
	{
		cout << "File \"" << inputFileName << "\" could not be opened" << endl;
	}
	else if (rows == 0) //is file does not have any contents
	{
		cout << "The input file \"" << inputFileName << "\" did not contain any data" << endl;
	}
	else //if the file can be opened
	{
		//displays the number of rows and columns
		cout << "Processing " << rows << " rows, and " << MAX_COLUMNS << " columns" << endl;

		//calculates average
		Average = average(grades, rows);
		cout << "Average for all values is " << fixed << setprecision(2) << Average << endl;

		//calculates and displays the average per column
		for (int i = 0; i < MAX_COLUMNS; i++)
		{
			cout << "Average for column " << i << " is " << fixed << setprecision(2) << columnAverage(grades, i, rows) << endl;
		}

		//calculates and displays the smallest value per row
		for (int j = 0; j < rows; j++)
		{
			cout << "Smallest value for row " << j << " is " << fixed << setprecision(2) << smallestRowValue(grades, j) << endl;
		}
	}

	//returns 0
	return 0;
}

/*
	the read file method opens a file and stores data into an array and then returns the number of contents
*/
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName)
{
	//variables
	int count = 0; //keeps track of contents
	double col0;
	double col1;
	double col2;
	double col3;
	double col4;
	int i = 0; //keeps track of while loop

	//opens file
	ifstream inputFile;
	inputFile.open(inputFileName);

	//checks to see if file can be opened
	if (!inputFile) //if file does not exist
	{
		inputFile.close(); //closes file
		return -1;
	}
	else //if file can be opened
	{
		while (inputFile >> col0 >> col1 >> col2 >> col3 >> col4) //reads in values
		{
			//stores values into array
			values[i][0] = col0;
			values[i][1] = col1;
			values[i][2] = col2;
			values[i][3] = col3;
			values[i][4] = col4;

			i++; //increases i
			count++; //increases count

			//checks to see if count is greater than 30
			if (count > maxRows)
			{
				inputFile.close(); //closes file
				return 30;
			}
			else if (count == maxRows)
			{
				inputFile.close(); //closes file
				return 30;
			}
		}

		//checks to see if there is less than 5 values
		if (count < 1) //if less than 5 values
		{
			inputFile.close(); //closes file
			return 0;
		}
		else //if 5 or more values
		{
			inputFile.close(); //closes file
			return count;
		}
	}
}
	
/*
	calculates the overall avergae of the data
*/
double average(double values[][MAX_COLUMNS], int numberRows)
{
	//variables
	double total = 0; //all the grades added together
	double average = 0; //stores average

	//goes through all the contents of array
	for (int i = 0; i < numberRows; i++)
	{
		for (int j = 0; j < MAX_COLUMNS; j++)
		{
			//adds value from array to tatal
			total += values[i][j];
		}
	}

	//calculates and returns average
	average = total/(MAX_COLUMNS*static_cast<double>(numberRows));
	return average;
}

/*
	column average method calculates the column average
*/
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
	//variables
	double totCol =0; //adds all the values of a column together
	double avgCol =0; //calculates the average of a column

	//goes through the column of the array
	for (int i = 0; i < numberRows; i++)
	{
		//adds the array value to totCol
		totCol += values[i][column];
	}

	//calculates and returns average
	avgCol = totCol / static_cast<double>(numberRows);
	return avgCol;
}

/*
	smallestRowValue method calculates and returns the smalles value of a row
*/
double smallestRowValue(double values[][MAX_COLUMNS], int numberRows)
{
	//variables
	double value = values[numberRows][0]; //keeps track of the smallest value

	//goes through the array
	for (int j = 0; j < MAX_COLUMNS; j++)
	{
	   if (values[numberRows][j] < value) //if the currnt value is smaller than the stored value
	   {
		   value = values[numberRows][j];
	   }
	}

	//returns the smallest value
	return value;
}
