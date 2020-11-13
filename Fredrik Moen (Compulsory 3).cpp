#include <iostream>
#include <conio.h>
#include <ctime>
#include "Header.h"
#include <string>




int randomColumn() {
	int randColumn = rand() % N;
	return randColumn;
}

int randomRow() {
	int randRow = rand() % M;
	return randRow;
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

	for (int n = 0; n <= ships-1; n++) {
		int x = randomColumn();
		int y = randomRow();

		if (n == 0) {
			shipX.push_back(x);
			shipY.push_back(y);
		}
		else {

			int existingShip = n;
			for (int a = 0; a <= n-1; a++) {
				if (shipX[a] == x && shipY[a] == y) {
					n--;
				}
			}
			if (existingShip == n) {
				shipX.push_back(x);
				shipY.push_back(y);
			}
		}
		/*std::cout << "[" << q << "]" << shipX[q] << shipY[q] << " ";
			if (q % 10 == 0 || q == 35) {
				std::cout << "\n";
			}*/
	}
	//
	//for (int n = 0; n <= numberOfShips-1; n++) {

	//	//if (n == 0) {
	//	//	shipX.push_back(x);
	//	//	shipY.push_back(y);
	//	//	//std::cout << shipX[0] << shipY[0];
	//	//}
	//	//else {

	//		int existingShip = n;
	//		//for (int a = 1; a <= n-1; a++) {
	//		//	//std::cout << shipX[a] << shipY[a];
	//		//	if (x == shipX[a]) {
	//		//		if (y = shipY[a]) {
	//		//			n--;
	//		//			
	//		//		}
	//		//	}
	//		//	//std::cout << a << " ";
	//		//}
	//		//std::cout << n << " ";
	//		if (existingShip == n) {
	//			shipX.push_back(x);
	//			shipY.push_back(y);
	//			//std::cout << n << " ";
	//		}
	//	//}
	//	/*std::cout << shipX.at(n);
	//	if (board[x][y] == SHIP) {
	//		n--;
	//	}
	//	else {
	//		board[x][y] = SHIP;
	//	}*/
	//		std::cout << "[" << n << "]" << shipX[n] << shipY[n] << " ";
	//		if (n % 10 == 0 || n == 35) {
	//			std::cout << "\n";
	//		}
	//}
	

}

//const char WHITE[8]{ 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
//const char RED[8]{ 0x1b, '[', '1', ';', '3', '1', 'm', 0 };



void printBoard() {
	MakeBoard(ships);
	for (int s = 0; s <= ships-1; s++) {
		board[shipX[s]][shipY[s]] = SHIP;
	}
	//board[shipX[0]][shipY[0]] = SHIP;
	makeEmptyBoard();
	writeLetters();
}

void printPlayerBoard() {
	//if (hits <= 1) {
		for (int h = 0; h <= hits - 1; h++) {
			board[hitY[h]][hitX[h]] = 'H';
		}
	//}
	//if (misses <= 1) {
		for (int m = 0; m <= misses - 1; m++) {
			board[missY[m]][missX[m]] = 'M';
		}
	//}
	makeEmptyBoard();
	writeLetters();
}

void shoot() {
	std::string shot;
	std::cout << "Choose which cell to shoot at: ";
	std::cout << "Shots: " << shots;
	std::cin >> shot;
	int shotX = shot.at(0) - 97;
	int shotY = shot.at(1) - 49;
	//std::cout << shotY << shotX;


	int hitTest = hits;
	for (int t = 0; t <= ships - 1; t++) {

		/*if (hits >= 1) {
			if (shotY == hitY[t] && shotX == hitX[t]) { std::cout << "brah"; }
		}
		if (misses >= 1) {
			if (shotY == missY[t] && shotX == missX[t]) { std::cout << "brah"; }
		}*/
		//else {
		if (shotY == shipY[t] && shotX == shipX[t]) {
			hits++;
			//std::cout << "hjui";
		}
	}
	
	if (hitTest != hits) {
		hitX.push_back(shotX);
		hitY.push_back(shotY);
	} else {

	//for (int tp = 0; tp <= ships - 1; tp++) {
		//if (shotY != shipY[tp] && shotX != shipX[tp]) {
			missX.push_back(shotX);
			missY.push_back(shotY);
			misses++;
			//std::cout << "hey";
		}
		//}
	//}

	
	
	shots--;
}

void battleship() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	MakeBoard(ships);
	//printBoard();
	printPlayerBoard();
	
	while (shots >= 1) {
		
		shoot();
		printPlayerBoard();
	}
	
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
