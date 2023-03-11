#include <iostream>
#include <fstream>
using namespace std;
/*******************************************************************
	 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/
class displayBoard {
public:
	char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	void disBoard() {
		cout << "\n\n\tTic Tac Toe\n\n";
		cout << "Player 1 (X)  -  Player 2 (O)" << endl;
		cout << endl;
		cout << "     |     |     " << endl;
		cout << "  " << square[1] << "  |  " << square[2] << "  |  "
			 << square[3] << endl;

		cout << "____|_____|____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[4] << "  |  " << square[5] << "  |  "
			 << square[6] << endl;

		cout << "____|_____|____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << square[7] << "  |  " << square[8] << "  |  "
			 << square[9] << endl;

		cout << "     |     |     " << endl << endl;
	}
};
class checkWin : public displayBoard {
public:
	int checkwin() {
		if (square[1] == square[2] && square[2] == square[3])

			return 1;
		else if (square[4] == square[5] && square[5] == square[6])

			return 1;
		else if (square[7] == square[8] && square[8] == square[9])

			return 1;
		else if (square[1] == square[4] && square[4] == square[7])

			return 1;
		else if (square[2] == square[5] && square[5] == square[8])

			return 1;
		else if (square[3] == square[6] && square[6] == square[9])

			return 1;
		else if (square[1] == square[5] && square[5] == square[9])

			return 1;
		else if (square[3] == square[5] && square[5] == square[7])

			return 1;
		else if (
			square[1] != '1' && square[2] != '2' && square[3] != '3' &&
			square[4] != '4' && square[5] != '5' && square[6] != '6' &&
			square[7] != '7' && square[8] != '8' && square[9] != '9')

			return 0;
		else
			return -1;
		displayBoard::disBoard();
	}
};
class playerTurn : public checkWin {
public:
	// int player = 1,i,choice;
	int playTurn() {
		int player = 1, i, choice;

		char mark;
		while (checkwin() == -1) {
			displayBoard::disBoard();
			player = (player % 2) ? 1 : 2;

			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			if (choice == 1 && square[1] == '1')

				square[1] = mark;
			else if (choice == 2 && square[2] == '2')

				square[2] = mark;
			else if (choice == 3 && square[3] == '3')

				square[3] = mark;
			else if (choice == 4 && square[4] == '4')

				square[4] = mark;
			else if (choice == 5 && square[5] == '5')

				square[5] = mark;
			else if (choice == 6 && square[6] == '6')

				square[6] = mark;
			else if (choice == 7 && square[7] == '7')

				square[7] = mark;
			else if (choice == 8 && square[8] == '8')

				square[8] = mark;
			else if (choice == 9 && square[9] == '9')

				square[9] = mark;
			else {
				cout << "Invalid move ";

				player--;
				// cin.ignore();
				// cin.get();
			}

			player++;
		}
		disBoard();
		if (checkwin() == 1) {
			cout << "Congratulations" << endl;
			cout << "==>>Player " << --player << " win!!! " << endl;
			ofstream file;
			file.open("File.txt", ios::out | ios::app);
			file << "==>>Player " << player << " win!!! " << endl;
			cout << "and the information is saved";
			file.close();
		} else {
			cout << "==>>Game draw!!!" << endl;
			ofstream file;
			file.open("File.txt", ios::out | ios::app);
			file << "==>>Game draw " << endl;
			cout << "and the information is saved";
			file.close();
		}
		// cin.ignore();
		// cin.get();
		return 0;
	}
};
int main() {
	displayBoard dis;
	playerTurn play;
	checkWin check;
	play.playTurn();
	check.checkwin();
}
