/*Beckett Maslia
date
Program 9
This is a tic tac toe game*/

#include <iostream>
using namespace std;

bool checkWin(char);
//check_win - checks if the player using the given character won
//@param char - the character the player is using

void displayBoard();
//displayBoard - displays the board to the users

char display[5][5] = { { ' ', '|', ' ', '|', ' ' },{ '-', '+', '-', '+', '-' },{ ' ', '|', ' ', '|', ' ' },{ '-', '+', '-', '+', '-' },{ ' ', '|', ' ', '|', ' ' } };

int main()
{
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } },
		player[2] = { ' ', ' ' },
		again = 'y';

	bool gameWon = false;

	while (again != 'n')
	{
		int turns = 0;
		cout << "Player 1 enter the character you are going to use (no spaces): ";
		cin >> player[0];
		while (player[0] == ' ' || player[0] == '	')
		{
			cout << "You entered a space (no spaces), re-enter a new character: ";
			cin >> player[0];
		}
		cout << endl << "Player 2 enter the character you are going to use (no spaces): ";
		cin >> player[1];
		while (player[1] == ' ' || player[1] == '	')
		{
			cout << "You entered a space (no spaces), re-enter a new character: ";
			cin >> player[1];
		}
		while (turns != 9 && !gameWon)
		{
			unsigned short x, y;
			cout << endl << endl;
			bool p1turn = true, p2turn = true;
			while (p1turn && turns != 9)
			{
				p1turn = false;
				displayBoard();
				cout << endl << endl << "Player 1: Enter 2 numbers (1-3) to mark off that place: ";
				cin >> x >> y;
				while (x > 3 || x < 1 || y > 3 || y < 1)
				{
					cout << "You must enter numbers from 1 to 3, please re-enter them: ";
					cin >> x >> y;
				}
				if (board[x - 1][y - 1] != ' ')
				{
					p1turn = true;
					cout << "You entered a coordinate that was already taken." << endl << endl;
				}
				else
				{
					board[x - 1][y - 1] = player[0];
					x = (x * 2) - 1;
					y = (y * 2) - 1;
					display[x - 1][y - 1] = player[0];
					if (checkWin(player[0])) gameWon = true;
					turns++;
				}
			}
			while (p2turn && turns != 9 && !gameWon)
			{
				p2turn = false;
				cout << endl;
				displayBoard();
				cout << endl << endl << "Player 2: Enter 2 numbers (1-3) to mark off that place: ";
				cin >> x >> y;
				while (x > 3 || x < 1 || y > 3 || y < 1)
				{
					cout << "You must enter numbers from 1 to 3, please re-enter them: ";
					cin >> x >> y;
				}
				if (board[x - 1][y - 1] != ' ')
				{
					p2turn = true;
					cout << "You entered a coordinate that was already taken." << endl << endl;
				}
				else
				{
					board[x - 1][y - 1] = player[1];
					x = (x * 2) - 1;
					y = (y * 2) - 1;
					display[x - 1][y - 1] = player[1];
					if (checkWin(player[1])) gameWon = true;
					turns++;
				}
			}
		}
		cout << endl << endl;
		displayBoard();
		if (checkWin(player[0]))
			cout << endl << endl << "And the winner is: Player 1!!!" << endl << endl;
		else if (checkWin(player[1]))
			cout << endl << endl << "And the winner is: Player 2!!!" << endl << endl;
		else cout << endl << endl << "And it looks like we have a draw folks. Cats Game." << endl << endl;
		cout << "Play again? (y/n): ";
		cin >> again;

		if (again != 'n')
		{
			for (int x = 1; x <= 3; x++)
				for (int y = 1; y <= 3; y++)
				{
					board[x - 1][y - 1] = ' ';
					display[(x * 2) - 2][(y * 2) - 2] = ' ';
				}
		}
	}

	cout << endl << endl;
	system("Pause");
	return 0;
}

bool checkWin(char player)
{
	bool result = false;
	for (int x = 0; x < 5; x += 2)
	{
		bool thisResult = true;
		for (int y = 0; y < 5; y += 2)
			thisResult = thisResult && display[x][y] == player;
		result = result || thisResult;
	}
	for (int x = 0; x < 5; x += 2)
	{
		bool thisResult = true;
		for (int y = 0; y < 5; y += 2)
			thisResult = thisResult && display[y][x] == player;
		result = result || thisResult;
	}
	bool thisResult[2] = { true, true };
	int y;
	for (int x = 0; x < 5; x += 2)
	{
		y = 4 - x;
		thisResult[0] = thisResult[0] && display[x][y] == player;
	}
	result = result || thisResult[0];
	for (int x = 0; x < 5; x += 2)
	{
		y = x;
		thisResult[0] = thisResult[0] && display[x][y] == player;
	}
	result = result || thisResult[0];
	return result;
}

void displayBoard()
{
	cout << " y:1 2 3" << endl << "x:" << endl;
	for (int x = 0; x < 5; x++)
	{
		if (x != 1 && x != 3) cout << (x + 2) / 2 << ". ";
		else cout << "   ";
		for (int y = 0; y < 5; y++)
			cout << display[x][y];
		cout << endl;
	}
}





/*#include <iostream>
#include <cstdlib>
using namespace std;

void Board();
void GetMove(char);

int GameBoard[3][3] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };

int main()
{
	char Player = 'X';
	int Turn = 0;

	cout << "Tic Tac Toe " << endl;
	cout << "Player X will go first, Player O will go second" << endl;

	Board();
	do
	{
		GetMove(Player);
		Board();

		if (Player == 'X')
			Player = 'O';
		else
			Player = 'X';

	} while (Turn < 10);

}

void Board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << GameBoard[i][j] << " ";
		}
		cout << endl;
	}
}

void GetMove(char Move)
{
	int MoveSpace;
	cout << "Enter the number of your desired move's space: ";
	cin >> MoveSpace;

	while (MoveSpace < 1 || MoveSpace > 9)
	{
		cout << "Input Invalid. Please select a space on the board: ";
		cin >> MoveSpace;
	}

	if (MoveSpace == 1)
		GameBoard[0][0] = Move;
	else if (MoveSpace == 2)
		GameBoard[0][1] = Move;
	else if (MoveSpace == 3)
		GameBoard[0][2] = Move;
	else if (MoveSpace == 4)
		GameBoard[1][0] = Move;
	else if (MoveSpace == 5)
		GameBoard[1][1] = Move;
	else if (MoveSpace == 6)
		GameBoard[1][2] = Move;
	else if (MoveSpace == 7)
		GameBoard[2][0] = Move;
	else if (MoveSpace == 8)
		GameBoard[2][1] = Move;
	else if (MoveSpace == 9)
		GameBoard[2][2] = Move;*/

	
//}
