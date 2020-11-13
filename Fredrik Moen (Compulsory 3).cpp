#include <iostream>
#include <conio.h>
#include <ctime>
#include "Header.h"
#include <string>
#include <iomanip>
#include <fstream>

int randomColumn() {
	int randColumn = rand() % N;
	return randColumn;
}

int randomRow() {
	int randRow = rand() % M;
	return randRow;
}

void makeEmptyBoard() {
	std::cout << "\n";
	for (int i = 0; i < N; i++) {
		std::cout << (i+1) << " ";
		for (int j = 0; j < M; j++) {
			std::cout << "[" << board[i][j] << "] ";
		}
		std::cout << "\n";
	}
}

void writeLetters() {
	char letters[6] = { 'A','B','C','D','E','F' };
	std::cout << " | ";
	for (int l = 0; l <= sizeof(letters) - 1; l++) {
		std::cout << letters[l] << " | ";
	}
	std::cout << "\n";
}

void MakeBoard(int numberOfShips) {
	for (int n = 0; n <= ships-1; n++) {
		int x = randomColumn();
		int y = randomRow();

		//The first time the ship has to be added because it cant compare to any earlier ships
		if (n == 0) {
			shipX.push_back(x);
			shipY.push_back(y);
		}

		else {
			int existingShip = n;
			for (int a = 0; a <= n-1; a++) {//checks all earlier ships position, if it is the same as any of them it starts over
				if (shipX[a] == x && shipY[a] == y) {
					n--;
				}
			}
			if (existingShip == n) {//if not it adds the ship
				shipX.push_back(x);
				shipY.push_back(y);
			}
		}
	}
}

void printBoard() {
	MakeBoard(ships);
	for (int s = 0; s <= ships-1; s++) {
		board[shipX[s]][shipY[s]] = SHIP;
	}
	makeEmptyBoard();
	writeLetters();
}

void printPlayerBoard() {
	for (int h = 0; h <= hits - 1; h++) {
		board[hitY[h]][hitX[h]] = 'H';
	}
	for (int m = 0; m <= misses - 1; m++) {
		board[missY[m]][missX[m]] = 'M';
	}
	makeEmptyBoard();
	writeLetters();
}

void shoot() {
	bool valid_input;
	do {
		std::string shot;
		std::cout << "Shots: " << shots;
		std::cout << "\nChoose which cell to shoot at: ";

		std::cin >> shot;
		int shotX = shot.at(0) - 97;//converts the string values to the correct int value
		int shotY = shot.at(1) - 49;

		if (shotX <= (-1) || shotX >= N || shotY <= (-1) || shotY >= M) {//makes sure you don't shoot outside the board
			valid_input = false;
			printPlayerBoard();
			std::cout << "Invalid input, try again\n\n";
		}
		else {
			valid_input = true;
		
			int hitTest = hits;
			for (int t = 0; t <= ships - 1; t++) {//if the shot is in the same position as a ship it is a hit
				if (shotY == shipY[t] && shotX == shipX[t]) {
				hits++;
				}
			}
			if (hitTest != hits) {
				hitX.push_back(shotX);
				hitY.push_back(shotY);
				remaining_ships--;
			} else {//else, it's a miss
				missX.push_back(shotX);
				missY.push_back(shotY);
				misses++;
			}
			shots--;
		}
	}while (valid_input == false);
}

void battleship() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	MakeBoard(ships);
	system("cls");
	printPlayerBoard();
	 do {
		shoot();
		system("cls");
		printPlayerBoard();
	 } while (shots >= 1 && remaining_ships != 0);
	 if (remaining_ships == 0) {
		 std::cout << "\n\nCongratulations, you hit all the ships!\n";
	 }
	 else {
		 std::cout << "\nYou are out of shots :(\n";
	 }
}

void chng_pswrd() {
	system("cls");
	bool advance = false;
	do {
		int user = 0;
		bool passComplete = false;
		int moves = 0;

		std::string new_password;
		
		do {
			std::string passLetters = { "ABCDEFGHIJKLMNOP" };
			passLetters[user] = '*';

			std::cout << "Enter new password\n";
			std::cout << "Use maximum 10 moves\n";
			std::cout << "Press spacebar to confirm password\n";

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

			std::cout << "\nUse W/A/S/D to move around";
			char c = _getch();
			moves ++;

			switch (c) {
			case('w'):
				user -= 4;
				if (user < 0) {
					user += 4;
					moves--;
				}
				new_password += passLetters[user];
				break;
			case('s'):
				user += 4;
				if (user > 15) {
					user -= 4;
					moves--;
				}
				new_password += passLetters[user];
				break;
			case('a'):
				user -= 1;
				if (user < 0) {
					user += 1;
					moves--;
				}
				new_password += passLetters[user];
				break;
			case('d'):
				user += 1;
				if (user > 15) {
					user -= 1;
					moves--;
				}
				new_password += passLetters[user];
				break;
			case(' '):
				passComplete = true;
				break;
			default:
				std::cout << "Not valid";
			}
			system("cls");
		} while (passComplete == false);
		if (moves >= 11) {
			advance = false;
			std::cout << "You used too many moves, start over";
			system("pause");
		}
		else {
			advance = true;

			std::fstream newPass("password.txt", std::ios::out);
			newPass << new_password;//sends the new password to the password text file
			newPass.close();
		}
	} while (advance == false);
	std::cout << "Your password has been changed\n\n";
	system("pause");
	system("cls");
}

void log_in(){
	bool login = false;
	int tries = 0;

	std::fstream pass("password.txt", std::ios::in);

	std::string password;
	pass >> password;//reads the password text file and stores it in a value;

	pass.close();

	do {
		std::string pAttempt;
		tries += 1;
		int moves = 0;
		int user = 0;
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

			std::cout << "\nUse " << (password.size() + 1) << " moves to enter the passcode\n";
			std::cout << "You have " << (4-tries) << " tries left\n";

			std::cout << "\nUse W/A/S/D to move around";
			char c = _getch();

			moves += 1;

			switch (c) {
			case('w'):
				user -= 4;
				if (user < 0) {
					user += 4;
					moves--;
				}
				pAttempt += passLetters[user];
				break;
			case('s'):
				user += 4;
				if (user > 15) {
					user -= 4;
					moves--;
				}
				pAttempt += passLetters[user];
				break;
			case('a'):
				user -= 1;
				if (user < 0) {
					user += 1;
					moves--;
				}
				pAttempt += passLetters[user];
				break;
			case('d'):
				user += 1;
				if (user > 15) {
					user -= 1;
					moves--;
				}
				pAttempt += passLetters[user];
				break;
			default:
				std::cout << "Not valid";
				moves--;
			}

			//if the password attempt matches the password the user can log in
			if (pAttempt == password) {
				login = true;
			}
			else {
				login = false;
			}
			system("cls");
		} while (moves <= password.size() && login == false);
		if (tries == 3 && login == false) {
			system("pause");
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
	log_in();
	menu();
}