#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX = 100;

string expenseName[MAX];
double expenseAmount[MAX];
int expenseCount = 0;

void addExpenses();
void viewExpensesList();
void setBudgetLimit();

int main() {
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
				exit(0);
				break;
			}

			if (toupper(exitChoice) == 'N') {
				cout << endl;
				break;
			}
		default:
			cout << "Invalid option. Please try again.\n" << endl;
			break;
		}
	}
	return 0;
}

void addExpenses() {

}

void viewExpensesList() {
	if (expenseCount == 0) {
		cout << "\nNo expenses recorded yet.\n" << endl;
		return;
	}

	cout << "\n===== EXPENSE LIST =====\n";
	cout << left << setw(5) << "No"
		<< setw(20) << "Expense"
		<< setw(10) << "Amount" << endl;

	cout << "-------------------------------\n";

	for (int i = 0; i < expenseCount; i++) {
		cout << left << setw(5) << i + 1
			<< setw(20) << expenseName[i]
			<< "RM " << fixed << setprecision(2) << expenseAmount[i] << endl;
	}

	cout << endl;
}


void setBudgetLimit() {

}