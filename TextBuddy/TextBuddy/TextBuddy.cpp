// Name: Prasoon Gupta
// Matric No.: A0116683B
//Assumptions: The user does not input more than 1 line in the program when the program asks for command.

#include "TextBuddy.h"

using namespace std;

const int REQ_NUM_OF_ARG = 2;
vector<string> tempStorage;
int NumberOfData = 0;


void updateFile(char* argv[]) {

	ofstream file(argv[1]);

	if (file.is_open()) {

		for (int i = 1; i <= NumberOfData; i++) {
			file << i << ". " << tempStorage[i - 1] << endl;
		}

		file.close();
	}

	return;
}


void add(string userData) {
	tempStorage.push_back(userData);
	return;
}

void del(int rowToDelete) {
	tempStorage.erase(tempStorage.begin() + rowToDelete - 1);
	return;
}

void display(char* argv[]) {
	if (NumberOfData > 0) {
		for (int i = 1; i <= NumberOfData; i++) {
			cout << i << ". " << tempStorage[i - 1] << endl;
		}
	}
	else {
		cout << argv[1] << " is empty." << endl;
	}

	return;
}

void clear() {
	tempStorage.erase(tempStorage.begin(), tempStorage.end());
	return;
}

void sortFile(vector<string>& tempStorage) {
	sort(tempStorage.begin(), tempStorage.end());
	return;
}

bool isFileSorted(vector<string>& tempStorage) {
	return is_sorted(tempStorage.begin(), tempStorage.end());
}

void collectData(char* argv[]) {

	string userCommand = "";
	string userData = "";
	int rowToDelete = NULL;

	cout << "command: ";
	cin >> userCommand;

	while (userCommand != "exit") {

		if (userCommand == "add") {
			getline(cin, userData);
			add(userData);
			NumberOfData++; 
			updateFile(argv);
			cout << "added to " << argv[1] << ": ''" << userData << "''" << endl;
		}
		else if (userCommand == "delete") {
			cin >> rowToDelete;
			cout << "deleted from " << argv[1] << ": ''" << tempStorage[rowToDelete - 1] << "''" << endl;
			del(rowToDelete);
			NumberOfData--;
			updateFile(argv);
		}
		else if (userCommand == "display") {
			display(argv);
		}
		else if (userCommand == "clear") {
			clear();
			NumberOfData = 0;
			updateFile(argv);
			cout << "all content deleted from " << argv[1] << endl;
		}
		else if (userCommand == "sort") {
			sortFile(tempStorage);
			if (isFileSorted(tempStorage)) {
				cout << "lines have been sorted." << endl;
			}
		}
		else {
			cout << "INVALID INPUT.\n";
		}

		cout << "command: ";
		cin >> userCommand;
		cout << endl;
		userData = "";
	}

	return;
}


int main(int argc, char* argv[]) {

	if (argc < REQ_NUM_OF_ARG) {
		cout << "Error: Uable to start TextBuddy" << endl;
	}
	else {
		cout << "Welcome to TextBuddy. " << argv[1] << " is ready for use." << endl;

		collectData(argv);
	}

	return 0;
}