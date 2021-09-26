/*
	Krithika Kannan
	CS 1136.102
	Lesson 10 Part 1
	27 November 2019
*/

//Header files
#include<iostream> //for cin/cout
#include<fstream> //for ifstream
#include <iomanip> //for fixed/setprecision
#include<string> //for string

using namespace std;

//prototypes
int read(char arr[], string& inputFileName); //for read function
void display(char studentAnswers[], char correctAnswers[], int numStudAns, int numCorrAns); //for display function

/* 
	This program calculates a student's quiz grade by checking their answers to an answer key
*/
int main()
{
	//Variables
	string fileNameStud; //stores student file name
	string fileNameAns; //stores answer file name

	char studentAnswers[30]; //stores students answers into an array
	char correctAnswers[30]; //stores correct answers into an array

	int numCorrAns; //stores the number of correct nswers 
	int numStudAns; //stores the number of student answers

	//gets file name
	cout << "Enter student answers file name" << endl;
	cin >> fileNameStud;

	//cals the read method and opens file
	numStudAns = read(studentAnswers, fileNameStud);

	//checks to see if file exists
	if (numStudAns == -1) //if file exists
	{
		cout << "File \"" << fileNameStud << "\" could not be opened" << endl;
	}
	else //if file does not exist
	{
		//gets answers file name
		cout << "Enter correct answer file name" << endl;
		cin >> fileNameAns;

		//calls read method and opens file
		numCorrAns = read(correctAnswers, fileNameAns);

		//checks to see if file exists
		if (numCorrAns ==-1) //if file does not exist
		{
			cout << "File \"" << fileNameAns << "\" could not be opened" << endl;
		}
		else //if file exists
		{
			//calls display method
			display(studentAnswers, correctAnswers, numStudAns, numCorrAns);
		}
	}
	//returns 0 if works
	return 0;
}

/*
	the read method checks to see if the file exists and returns the number of items in the file
*/
int read(char arr[], string& inputFileName)
{
	//variables
	int count = -1; //keeps track of number of contents
	char answer; //stores char contents of file

	//opens file
	ifstream inputFile;
	inputFile.open(inputFileName);

	//checks to see if the file exits 
	if (!inputFile) //if file does not exist
	{
		inputFile.close();
		return -1;
	}
	else //if file does exist
	{
		//reads in the contentes to an array
		while (inputFile >> answer) 
		{
			count++; //increases count
			arr[count] = answer; //stores into array
			
			//if count is more than 30
			if (count > 29)
			{
				return 30;
			}
		}

		//closes file and returns count
		inputFile.close();
		return count+1;
	}

	//if method does not work return -1
	return -1;
}

/*
	display method calculates student's grade and displays the questions the student missed
*/
void display(char studentAnswers[], char correctAnswers[], int numStudAns, int numCorrAns)
{
	//variables
	double numQuestionsMissed = 0; //stores the number of questions the student missed
	double percentCorrect = 0; //stores the percent of questions the student got correct

	//checks if grades can be calculated
	if (numStudAns == 0 && numCorrAns == 0) //if there are no contents of each file
	{
		cout << "The number of student answers and correct answers are both 0" << endl;
		cout << "No grade can be calculated" << endl;
	}
	else if (numStudAns != numCorrAns) //if one file has more contents
	{
		cout << "The student answers file has " << numStudAns << " entries and the correct answers file has " 
			 << numCorrAns << " entries" << endl;
		cout << "Grading cannot be done if they are not the same" << endl;
	}
	else //if both files can be compared
	{
		//goes through each array
		for (int i = 0; i < numCorrAns; i++)
		{
			if (studentAnswers[i] != correctAnswers[i]) //if the answer is wrong
			{
				numQuestionsMissed++; //increase the number of questions missed
				cout << "Question " << i+1 << " has incorrect answer \'" << studentAnswers[i] 
					 << "\', the correct answer is \'"<< correctAnswers[i] <<"\'" << endl;
			}
		}

		//calculates the percent of questions correct
		percentCorrect = (numCorrAns - numQuestionsMissed) / numCorrAns * 100;

		//Prints out the number of questions missed
		cout << numQuestionsMissed << " questions were missed out of " << numCorrAns << endl;
		cout << "The student grade is " << fixed << setprecision(1) << percentCorrect << "%" << endl;

		//checks if student passed
		if (percentCorrect >= 70) //if student passed
		{
			cout << "The student passed" << endl;
		}
		else //if student failed
		{
			cout << "The student failed" << endl;
		}
	}
}