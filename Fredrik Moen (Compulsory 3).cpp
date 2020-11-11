#include <iostream>
#include <conio.h>
#include <ctime>
#include "Header.h"
#include <string>

int randomRow() {
	int randRow = rand() % M;
	return randRow;
}

int randomColumn() {
	int randColumn = rand() % N;
	return randColumn;
}

void makeEmptyBoard() {
	
	for (int i = 0; i < N; i++) {
		std::cout << " ";
		for (int j = 0; j < M; j++) {
			std::cout << "[" << board[i][j] << "] ";
		}
		std::cout << "\n";
	}
}

void writeLetters() {
	char letters[6] = { 'A','B','C','D','E','F' };
	std::cout << "| ";
	for (int l = 0; l <= sizeof(letters) - 1; l++) {
		std::cout << letters[l] << " | ";
	}
}

void MakeBoard(int numberOfShips) {
	const char SHIP = 'S';
	for (int n = 0; n <= numberOfShips-1; n++) {

		int x = randomColumn();
		int y = randomRow();

		if (board[x][y] == SHIP) {
			n--;
		}
		else {
			board[x][y] = SHIP;
		}
	}
}

//const char WHITE[8]{ 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
//const char RED[8]{ 0x1b, '[', '1', ';', '3', '1', 'm', 0 };



void printBoard() {
	MakeBoard(3);
	makeEmptyBoard();
	writeLetters();
}

void printPlayerBoard() {

	

	for (int h = 0; h <= shots_taken-1;h++) {
		board[hitX[h]][hitY[h]] = 'H';
		/*std::cout << hitX[h] << " " << hitY[h];
		std::cout << h;*/
		std::cout << hitX[h];
		std::cout << hitY[h] << " ";
	}

	makeEmptyBoard();
	writeLetters();
}


void battleship() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	printPlayerBoard();
	//printBoard();
}


void chng_pswrd() {



}


void log_in(){
	bool login = false;
	int tries = 0;
	do {
		tries += 1;

		int moves = 0;
		int user = 0;
		std::string password;
		std::string pTry = "BCDHLPONM";
		do {

			std::string passLetters = { "ABCDEFGHIJKLMNOP" };
			passLetters[user] = '*';

			std::cout << "\n  |  " << passLetters[0] << "  ";
			std::cout << "|  " << passLetters[1] << "  ";
			std::cout << "|  " << passLetters[2] << "  ";
			std::cout << "|  " << passLetters[3] << "  |\n";
			std::cout << "  |  " << passLetters[4] << "  ";
			std::cout << "|  " << passLetters[5] << "  ";
			std::cout << "|  " << passLetters[6] << "  ";
			std::cout << "|  " << passLetters[7] << "  |\n";
			std::cout << "  |  " << passLetters[8] << "  ";
			std::cout << "|  " << passLetters[9] << "  ";
			std::cout << "|  " << passLetters[10] << "  ";
			std::cout << "|  " << passLetters[11] << "  |\n";
			std::cout << "  |  " << passLetters[12] << "  ";
			std::cout << "|  " << passLetters[13] << "  ";
			std::cout << "|  " << passLetters[14] << "  ";
			std::cout << "|  " << passLetters[15] << "  |\n";
			std::endl(std::cout);

			std::cout << "\nUse 9 moves to enter the passcode\n";
			std::cout << "You have 3 tries\n";

			std::cout << "\nUse W/A/S/D to move around";
			char r = _getch();

			moves += 1;

			switch (r) {
			case('w'):
				user -= 4;
				if (user < 0) {
					user += 4;
					moves--;
				}
				password += passLetters[user];

				break;
			case('s'):
				user += 4;
				if (user > 15) {
					user -= 4;
					moves--;
				}
				password += passLetters[user];
				break;
			case('a'):
				user -= 1;
				if (user < 0) {
					user += 1;
					moves--;
				}
				password += passLetters[user];
				break;
			case('d'):
				user += 1;
				if (user > 15) {
					user -= 1;
					moves--;
				}
				password += passLetters[user];
				break;
			default:
				std::cout << "Not valid";
				moves--;
			}

			//if the Password matches the password attempt the user can log in
			if (password == pTry) {
				login = true;
			}
			system("cls");
		} while (moves != 9 && login == false);

		if (tries == 4) {
			std::exit(0);
		}
	} while (login == false);
	}

void menu() {
	//Main menu
	bool exitprogram = false;
	do {
		int answer;
		std::cout << "1. Change password\n";
		std::cout << "2. Play battleship\n";
		std::cout << "3. Quit\n\n";
		std::cout << "Select an option(1-3): ";

		std::cin >> answer;

		switch (answer) {
		case(1):
			chng_pswrd();
			break;
		case(2):
			battleship();
			break;
		case(3):
			exitprogram = true;
			break;
		default:
			std::cout << "Wrong input... Try again";
		}

	} while (exitprogram == false);


}

int main() {

	//writeLetters();
	battleship();
	//log_in();
	//menu();

}
