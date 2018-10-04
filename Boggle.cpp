/*Sean Gorham
*CS240 Section 001
*Program 1 BOGGLE
*This program simulates a boggle game, the board shakes 500 times and asks the user to type
*a word and see if the letters are in the current boggle board and if they can shout BOGGLE!
*/

#include <iostream>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void loadCaps(string dice[16]);
void loadBoard(string dice[4][4]);
void clearScreen();
void shakeBoard(string dice[4][4]);

//main function
int main() {
	string dieFaces[16];
		

	loadCaps(dieFaces);
	loadBoard(dieFaces);
	shakeBoard(dieFaces);
	askForWord();

	
	return 0;
}

//clearScreen: used for wiping the screen between each shake of the board.
void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	// Assume POSIX
	system("clear");
#endif
}


//loadCaps: load letters from a text file into a 2D array
void loadCaps(string dice[16]) {
	ifstream infile;
	string tmp;
	int i = 0;
	char dieFaces[16][6];

	infile.open("BoggleDicecaps.txt");

	while (!(infile.eof())) {
		infile >> tmp;
		if (!(infile.fail())) {
			dice[i] = tmp;
			cout << dice[i] << endl;
		}
		i++;
	}

	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 6; c++) {
			dice[r][c] = dieFaces[r][c];
		}
	}	
}



//shakeBoard: shake the board to jumble the letters of the boggle board
void shakeBoard(string dice[4][4]) {
	srand(unsigned(time(NULL)));
	string tmp;

	for (int i = 0; i < 517; i++) {
		int row0 = (rand() % 4);
		int row1 = (rand() % 4);
		int col = (rand() % 4);

		clearScreen();

		tmp = dice[row0][col];
		dice[row0][col] = dice[row1][col];
		dice[row1][col] = tmp;
		
		loadBoard(dice);
	}
}


//loadBoard: load the boggle board with the dice
void loadBoard(string dice[4][4]) {
	string faces[16];
	srand(unsigned(time(NULL)));

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			int z = r += c;
			faces[z] = dice[r][c];
		}
	}

	

	cout << "+---+---+---+---+" << endl;
		for(int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << "| " <<  faces[4][3] << " ";
			
			}
			cout << "|\n+---+---+---+---+" << endl;
		}

}


askForWord: ask the user for a word and see if the letters are on the board 
ignoring normal boggle rules
void askForWord(string faces[4][4]) {
	string enteredWord;

	do {
		cout << "Enter a word to see if it is in the current boggle board. Enter 0 to quit." << endl;
		cin >> enteredWord;
		if (enteredWord == faces) {
			cout << "That word was found!" << endl;
		}
		else {
			cout << "That word was not found, work on your spelling!" << endl;
		}
	} while (enteredWord != "0");
}
