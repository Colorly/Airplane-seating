#include <iostream>

using namespace std;
const int ROWS = 13;
const int COLS = 6;
char seats[ROWS][COLS];
void init() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			seats[i][j] = '*';
		}
	}
}
void printMenu() {
	cout << "********************" << endl;
	cout << "Plane Seat" << endl;
	cout << "Press 0 to reserve one seat\n";
	cout << "PRess 1 to reserve more than one seats\n";
	cout << "Press 2 to show the current seating\n";
	cout << "3 : Exit\n";
	cout << "********************" << endl;
	cout << "Enter the choice number : ";
}

void printSeats() {
	cout << "\nCurrent Seating : \n\n";

	cout << "     A B C D E F " << endl;


	for (int i = 0; i < ROWS; ++i) {
		cout << "ROW" << i + 1 << " ";
		for (int j = 0; j < COLS; ++j) {
			cout << seats[i][j] << " ";
		}
		cout << "\n";
	}
}

void getSeatInput(int &rowNum, char &colChar) {
	cin >> rowNum >> colChar;
}

int convertColChar(const char &c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	return c - 'a';
}

bool checkAvailability(const int &rowNum, const int &colNum) {
	if (seats[rowNum][colNum] == '*')
		return true;
	return false;
}

void reserveSeat() {
	while (true) {
		cout << "Enter row number and column letter seperated by space :\n";
		int rowNum;
		char colChar;
		getSeatInput(rowNum, colChar);
		if (rowNum < 1 || rowNum > ROWS || convertColChar(colChar) < 0 || convertColChar(colChar) >= COLS) {
			cout << "Invalid Seat Number, Please Try again !\n";
			continue;
		}
		if (checkAvailability(rowNum - 1, convertColChar(colChar))) {
			seats[rowNum - 1][convertColChar(colChar)] = 'X';
			break;
		}
		else {
			cout << "Seat not available, Enter another seat number.\n";
		}
	}
	printSeats();
}

void reserveSeat(const int &numSeats) {
	int reserveCt = 0;
	while (reserveCt != numSeats) {
		while (true) {
			cout << "Enter row number and column letter seperated by space for seat " << reserveCt + 1 << " : \n";
			int rowNum;
			char colChar;
			getSeatInput(rowNum, colChar);
			if (rowNum < 1 || rowNum > ROWS || convertColChar(colChar) < 0 || convertColChar(colChar) >= COLS) {
				cout << "Invalid Seat Number, Please Try again !\n";
				continue;
			}
			if (checkAvailability(rowNum - 1, convertColChar(colChar))) {
				seats[rowNum - 1][convertColChar(colChar)] = 'X';
				break;
			}
			else {
				cout << "Seat not available, Enter another seat number.\n";
			}
		}
		reserveCt++;
	}
	printSeats();
}

int main() {
	init();
	while (true) {
		printMenu();
		int choice;
		cin >> choice;
		if (choice == 0) {
			reserveSeat();
		}
		else if (choice == 1) {
			cout << "Enter number of seats : ";
			int numSeats;
			cin >> numSeats;
			reserveSeat(numSeats);
		}
		else if (choice == 2) {
			printSeats();
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "\nInvalid option, Please Try again !\n\n";
		}
	}
	return 0;
}
