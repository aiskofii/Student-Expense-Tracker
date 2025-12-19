#include <iostream>
#include <iomanip>
using namespace std;
void mainMenu();
void addExpenses();
void viewExpensesList();
void setBudgetLimit();

int main() {
	mainMenu();


	return 0;
}

void mainMenu() {
	int option;
	char exitChoice;
	bool exitStatus = false;

	while (!exitStatus) {
		cout << "*** STUDENT EXPENSE TRACKER ***" << endl;
		cout << "===============================\n" << endl;
		cout << "1. Add expenses" << endl;
		cout << "2. View expenses list" << endl;
		cout << "3. Set budget limit" << endl;
		cout << "4. Exit program\n" << endl;

		cout << "Select your option (1-4): ";
		cin >> option;

		switch (option) {
		case 1:
			addExpenses();
			break;
		case 2:
			viewExpensesList();
			break;
		case 3:
			setBudgetLimit();
			break;
		case 4:
			cout << "Are you sure you want to exit? (Y/N): ";
			cin >> exitChoice;

			if (toupper(exitChoice) == 'Y') {
				cout << "Exiting program. Goodbye!" << endl;
				exitStatus = true;
				break;
			}

			if (toupper(exitChoice) == 'N') {
				cout << endl;
				mainMenu();
				break;
			}
		default:
			cout << "Invalid option. Please try again.\n" << endl;
			mainMenu();
			break;
		}
	}
}

void addExpenses() {
	
}

void viewExpensesList() {

}

void setBudgetLimit() {

}