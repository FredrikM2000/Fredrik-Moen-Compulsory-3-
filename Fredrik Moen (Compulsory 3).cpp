#include <iostream>
#include <conio.h>
#include <ctime>
#include "Header.h"

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
		for (int j = 0; j < M; j++) {
			std::cout << "[" << board[i][j] << "]";
		}
		std::cout << "\n";
	}
}

void writeLetters() {
	char letters[6] = { 'A','B','C','D','E','F' };
	std::cout << "|";
	for (int l = 0; l <= sizeof(letters) - 1; l++) {
		std::cout << letters[l] << "|";
	}
}

void MakeBoard(int numberOfShips) {
	const char SHIP = 'S';
	for (int n = 0; n <= numberOfShips-1; n++) {
		//std::cout << n;
		if (board[randomColumn()][randomRow()] == ' ') {
			/*n--;
			std::cout << "|";*/
			board[randomColumn()][randomRow()] = SHIP;
		}
		else {
		//	board[randomColumn()][randomRow()] = SHIP;
			n--;
		}
		//makeEmptyBoard();
		//std::cout << "\n";
	}
}


//TODO: separer makeemptyboard og printboard 


void printBoard() {
	MakeBoard(4);
	makeEmptyBoard();
	//writeLetters();
}


void battleship() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	
	printBoard();
}





void chng_pswrd() {



}






int main() {


	battleship();

//	bool move1 = false;
//	bool move2 = false;
//	bool move3 = false;
//	bool move4 = false;
//	bool move5 = false;
//	bool move6 = false;
//	bool move7 = false;
//	bool move8 = false;
//	bool move9 = false;
//
//	bool login = false;
//	int tries = 0;
//	do {
//		tries += 1;
//
//		int moves = 0;
//		int user = 0;
//		do {
//
//			char arr[16] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
//			arr[user] = '*';
//
//
//			std::cout << "\n  |  " << arr[0] << "  ";
//			std::cout << "|  " << arr[1] << "  ";
//			std::cout << "|  " << arr[2] << "  ";
//			std::cout << "|  " << arr[3] << "  |\n";
//			std::cout << "  |  " << arr[4] << "  ";
//			std::cout << "|  " << arr[5] << "  ";
//			std::cout << "|  " << arr[6] << "  ";
//			std::cout << "|  " << arr[7] << "  |\n";
//			std::cout << "  |  " << arr[8] << "  ";
//			std::cout << "|  " << arr[9] << "  ";
//			std::cout << "|  " << arr[10] << "  ";
//			std::cout << "|  " << arr[11] << "  |\n";
//			std::cout << "  |  " << arr[12] << "  ";
//			std::cout << "|  " << arr[13] << "  ";
//			std::cout << "|  " << arr[14] << "  ";
//			std::cout << "|  " << arr[15] << "  |\n";
//			std::endl(std::cout);
//
//			std::cout << "\nUse 9 moves to enter the passcode\n";
//			std::cout << "You have 3 tries\n";
//
//			std::cout << "\nUse W/A/S/D to move around";
//			char r = _getch();
//
//			moves += 1;
//
//			switch (r) {
//			case('w'):
//				user -= 4;
//				if (user < 0) {
//					user += 4;
//					moves--;
//				}
//				break;
//			case('s'):
//				user += 4;
//				if (user > 15) {
//					user -= 4;
//					moves--;
//				}
//				break;
//			case('a'):
//				user -= 1;
//				if (user < 0) {
//					user += 1;
//					moves--;
//				}
//				break;
//			case('d'):
//				user += 1;
//				if (user > 15) {
//					user -= 1;
//					moves--;
//				}
//				break;
//			default:
//				std::cout << "Not valid";
//				moves--;
//			}
//
//			if (moves == 1 && user == 1) {
//				move1 = true;
//			}
//			if (moves == 2 && user == 2) {
//				move2 = true;
//			}
//			if (moves == 3 && user == 3) {
//				move3 = true;
//			}
//			if (moves == 4 && user == 7) {
//				move4 = true;
//			}
//			if (moves == 5 && user == 11) {
//				move5 = true;
//			}
//			if (moves == 6 && user == 15) {
//				move6 = true;
//			}
//			if (moves == 7 && user == 14) {
//				move7 = true;
//			}
//			if (moves == 8 && user == 13) {
//				move8 = true;
//			}
//			if (moves == 9 && user == 12) {
//				move9 = true;
//			}
//			
//			
//			//if the move matches the digit, you will be able to login
//			if (move1 == true && move2 == true && move3 == true && move4 == true && move5 == true && move6 == true && move7 == true && move8 == true && move9 == true) {
//				login = true;
//			}
//
//			system("cls");
//
//		} while (moves != 9 && login == false);
//
//
//		/*if (moves == 1 && user == 3) {
//			login = true;
//		}*/
//		if (tries == 4) {
//			std::exit(0);
//		}
//	} while (login == false);
//
//	//Main menu
//
//
//	bool exitprogram = false;
//	do {
//	int answer;
//	std::cout << "1. Change password\n";
//	std::cout << "2. Play battleship\n";
//	std::cout << "3. Quit\n\n";
//	std::cout << "Select an option(1-3): ";
//
//	std::cin >> answer;
//
//		switch (answer) {
//		case(1):
//			chng_pswrd();
//			break;
//		case(2):
//			battleship();
//			break;
//		case(3):
//			exitprogram = true;
//			break;
//		default:
//			std::cout << "Wrong input... Try again";
//		}
//
//	} while (exitprogram == false);
//



}
