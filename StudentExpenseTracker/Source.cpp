#include <iostream>				// libraries used
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <string>
using namespace std;

const int MAX = 100;

string expenseName[MAX];		// global arrays and variables used
double expenseAmount[MAX];
int expenseCount = 0;
double budgetLimit = 0;
bool budgetSet = false;

void addExpenses();				// function prototypes for every feature
void viewExpensesList();
void setBudgetLimit();

int main() {
	int option;
	char exitChoice;

	while (true) {
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
	if (expenseCount >= MAX) {
		cout << "\nExpense list is full!\n" << endl;
		return;
	}

	double amount;
	while (true) {
		cout << "\nEnter expense amount (RM): ";
		if (!(cin >> amount)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a numeric value.\n";
			continue;
		}

		if (amount < 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Amount cannot be negative. Please enter a non-negative value.\n";
			continue;
		}

		// consume leftover newline so getline below works
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;
	}

	cout << "Enter expense reference: ";
	string name;
	getline(cin, name);

	while (name.empty()) {
		cout << "Reference cannot be empty. Enter expense reference: ";
		getline(cin, name);
	}

	expenseAmount[expenseCount] = amount;
	expenseName[expenseCount] = name;
	expenseCount++;
	cout << "Expense added successfully!\n" << endl;

	double total = 0.0;
	for (int i = 0; i < expenseCount; i++) total += expenseAmount[i];

	if (!budgetSet) {
		cout << "Note: Budget limit is not set. Use option 3 to set a budget limit.\n" << endl;
	}
	else {
		cout << "Total expenses: RM " << fixed << setprecision(2) << total << endl;
		if (total > budgetLimit) {
			cout << "Warning: You have exceeded the budget by RM " << fixed << setprecision(2) << (total - budgetLimit) << ".\n" << endl;
		}
		else {
			cout << "You are within the budget. Remaining: RM " << fixed << setprecision(2) << (budgetLimit - total) << ".\n" << endl;
		}
	}
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

	double total = 0.0;
	for (int i = 0; i < expenseCount; i++) total += expenseAmount[i];

	cout << "Total expenses: RM " << fixed << setprecision(2) << total << endl;

	if (!budgetSet) {
		cout << "Note: Budget limit is not set. Use option 3 to set a budget limit.\n" << endl;
	}
	else {
		if (total > budgetLimit) {
			cout << "Warning: You have exceeded the budget by RM " << fixed << setprecision(2) << (total - budgetLimit) << ".\n" << endl;
		}
		else {
			cout << "You are within the budget. Remaining: RM " << fixed << setprecision(2) << (budgetLimit - total) << ".\n" << endl;
		}
	}
}


void setBudgetLimit() {
	double input;
	char choice;

	if (budgetSet) {
		cout << "\nCurrent budget limit: RM " << fixed << setprecision(2) << budgetLimit << endl;
		cout << "Do you want to replace it? (Y/N): ";
		cin >> choice;
		if (toupper(choice) != 'Y') {
			cout << "Budget limit unchanged.\n" << endl;
			return;
		}
	}

	while (true) {
		cout << "\nEnter new budget limit (RM): ";
		cin >> input;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a numeric value.\n";
			continue;
		}

		if (input < 0) {
			cout << "Budget cannot be negative. Please enter a non-negative value.\n";
			continue;
		}

		budgetLimit = input;
		budgetSet = true;
		cout << "Budget limit set to RM " << fixed << setprecision(2) << budgetLimit << ".\n" << endl;
		break;
	}

	if (expenseCount > 0) {
		double total = 0.0;
		for (int i = 0; i < expenseCount; i++) total += expenseAmount[i];

		cout << "Total expenses: RM " << fixed << setprecision(2) << total << endl;
		if (total > budgetLimit) {
			cout << "Warning: You have exceeded the budget by RM " << fixed << setprecision(2) << (total - budgetLimit) << ".\n" << endl;
		}
		else {
			cout << "You are within the budget. Remaining: RM " << fixed << setprecision(2) << (budgetLimit - total) << ".\n" << endl;
		}
	}
}