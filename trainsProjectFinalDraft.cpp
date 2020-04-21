#include <iostream>
#include <vector>
#include <string>
using namespace std;

void departuresToLA() {					// When train leaves from OC to LA
	for (int i = 0; i < 17; i++) {
		cout << "|Train departs from OC at: " << i + 5 << ":00|" << endl;
		cout << "----------------------------------" << endl;
	}
}
void departuresToSD() {					// When train leaves from OC to SD
	for (int i = 0; i < 17; i += 2) {
		cout << " |Train departs from OC at: " << i + 5 << ":00|" << endl;
		cout << " ----------------------------------" << endl;
	}
}
void arrivalToLA() {					 // When train arrives to LA
	for (int i = 0; i < 19; i++) {
		cout << "|Train Arrivals: " << i + 6 << ":00|" << endl;
		cout << "----------------------------------" << endl;
	}
}

void arrivalToSD() {				    // When train arrives to SD
	for (int i = 0; i < 18; i += 2) {
		cout << "|Train Arrivals: " << i + 7 << ":00|" << endl;
		cout << " -------------------------------" << endl;
	}
}


int main() {

	int outerUserInput;
	int innerUserInput;
	char viewMenuInput;
	char quitProgram;
	vector<int> evenNum{2, 4, 6, 8, 10, 12, 14, 16, 18, 22, 24};		// Vector to check for error bounds

    cout << "Welcome to Amtrak Scheduling System!" << endl;             // Outer System menu
	cout << "Please select an option. ";                
	cout << "Where do you want to go?\n";			                    // User selects where they want to go
	cout << "Enter 1 for Los Angeles.\n";
	cout << "Enter 2 for San Diego.\n";
	cin >> outerUserInput;

	if (outerUserInput == 1) {	    // Departures to LA
		departuresToLA();
		cout << "What time do you want to leave? Input a time between 5-21 (5 AM - 9 PM).\n";		// Inner System Menu
		cin >> innerUserInput;																		// User selects a time they want to leave
		cout << endl;               
		while (innerUserInput < 5 || innerUserInput > 21) {
			cout << "Invalid input. Please input a time that is on the schedule." << endl;
			cin >> innerUserInput;
			cout<< endl;            
		}
			cout << "You will depart Orange County at " << innerUserInput << ":00" << " and arrive in Los Angeles at " << innerUserInput + 1 << ":00. The travel time is 1 hour.\n";
	}
	if (outerUserInput == 2) {      // Departures to SD
		departuresToSD();
		cout << "What time do you want to leave? Input a time between 5-21(5 AM - 9 PM).\n";		// Inner System Menu
		cin >> innerUserInput;																		// User selects a time they want to leave
        cout << endl;                   
		for (unsigned int i = 0; i < evenNum.size(); i++) {			// Loop to continue running inner loop
			for (unsigned int i = 0; i < evenNum.size(); i++) {		// Inner loop to check for invalid input		
				if (innerUserInput == evenNum.at(i)) {
					cout << "Invalid input. Please input a time that is on the schedule." << endl;  // User prompted to input time again if first input is invalid 
					cin >> innerUserInput;
					cout << endl;       
				}
			}
		}
		cout << "You will depart Orange County at " << innerUserInput << ":00" << " and arrive in San Diego at " << innerUserInput + 2 << ":00. The travel time is 2 hours.\n";
	}
	
	cout << "You will be notified if your train is delayed." << endl << endl;
	cout << "Would you like to see the schedule again? Enter (y) for yes and (n) for no." << endl;		// Gives user option of seeing schedule again.
	cin >> viewMenuInput;
    cout << endl;                    

	if (viewMenuInput == 'y') {		// If statement for if user wants to see schedule again
		if (outerUserInput == 1) {
			departuresToLA();		// Shows same menu as user selected earlier
		}
		else if (outerUserInput == 2) {	
			departuresToSD();
		}
		cout << "Would you like to schedule a new trip? Enter (y) for yes and (n) for no." << endl;	// Gives user option of quitting program
		cin >> quitProgram;
        cout << endl;               

		if (quitProgram == 'n') {
			cout << "Thank you. Please come again soon.\n";		// Exits program
		}
		else if (quitProgram == 'y') {
		    cout << "----------------------------------" << endl;   
			main();		// Reruns the whole program
		}	
	}
	else if (viewMenuInput == 'n') {
		cout << "Would you like to schedule a new trip? Enter (y) for yes and (n) for no." << endl;		// Gives user option of quitting program
		cin >> quitProgram;
        cout << endl;           

		if (quitProgram == 'n') {
			cout << "Thank you! Please come again soon.\n";	// Exits program
			
		}
		else if (quitProgram == 'y') {
		    cout << "-----------------------------------\n";  
			main();		// Reruns the whole program
		}
	}

	return 0;
}

