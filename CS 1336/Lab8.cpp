/* CS1336 - Homework #8
   Name  : Krithika Kannan
   NetID : kxk180046
   Date  : October 27, 2019
*/

//Header files
#include <iostream>
#include <iomanip>

using namespace std;

//This program calculates the occupancy of a hotel
int main()
{
    //Variables
    int totalFloors;
    int totalRooms;
    int totalOccupied;
    int numRooms;
    int numOccupied;
    double percentage;
  
    //Keeps asking the user to enter the number of floors in the hotel until a valid number is entered
    do{
        cout << "How many floors does the hotel have(can't be less than 1): " << endl;
        cin >> totalFloors;
        if(totalFloors<1)
        {
            cout << "Value entered is invalid." << endl;
        }
    }while(totalFloors<1);
    
        //loops through the number of floors in the hotel
        for(int i=1; i<=totalFloors; i++)
        {
            if(i==13) //skips the 13th floor
            {
                continue;
            }
            
            //keeps asking the user to enter the number rooms in the floor until valid number entered
            do{
                cout << "Enter the number of rooms in floor " << i << " (can't be less than 10): " << endl;
                cin >> numRooms;
                if(numRooms<10)
                {
                    cout << "Value entered is invalid." << endl;
                }
            }while (numRooms<10);
    
            totalRooms += numRooms;// adds the number of rooms on the floor to the total number of rooms
            
            //keeps asking the user to enter the occupied rooms on the floors until valid number entered
            do{
                cout << "Enter the number of rooms that are occupied on floor " << i << ": " << endl;
                cin >> numOccupied;
                if(numOccupied > numRooms)
                {
                    cout << "The number of rooms occupied can't be greater than the number of rooms on the floor." << endl;
                }
            }while(numOccupied > numRooms);
            
            totalOccupied +=numOccupied; //ads the number of unoccupied rooms on the floors to the total
        }
        
        //Display
        cout << endl;
        cout << "Total number of rooms that the hotel has: " << totalRooms << endl;
        cout << "Total number of rooms that are occupied in the hotel: " << numOccupied << endl;
        cout << "Total number of rooms that are unoccupied in the hotel: " << totalRooms - numOccupied << endl;
        percentage = static_cast<double> (numOccupied) / totalRooms * 100; //calculates percentage of rooms occupied
        cout << "Percentage of rooms that are occupied: " << fixed << setprecision(2)  << percentage << "%" << endl;

    //The program returns 0
    return 0;
}
