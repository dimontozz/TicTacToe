#include <iostream>
#include <conio.h>

using namespace std;

void printInputMatrix();
void printBoard();
int addMark();
int check();

char board[3][3] = { ' ',' ',' ',
					' ',' ',' ',
					' ',' ',' ' };
int turn = 1;
char mark = 'O';
int input;

int main()
{
	setlocale(LC_ALL, "Russian");

	int won = 0;
	int validInput = 0;

	for (int i = 0; i < 9; i++)
	{
		system("cls");
		printBoard();
		if (turn) cout << "Гравець 1 хід (символ : O)" << endl;
		else cout << "Гравець 2 хід (символ : Х)" << endl;
		printInputMatrix();
		cout << "Введіть введення з вхідної матриці: ";
		cin >> input;
		while (input < 0 || input > 9)
		{
			cout << "Неправильні дані. Будь ласка, введіть ще раз: ";
			cin >> input;
		}
		if (turn) mark = 'O';
		else mark = 'X';

		validInput = addMark();
		if (!validInput)
		{
			i--;
			continue;
		}
		won = check();
		if (won)
		{
			system("cls");
			printBoard();
			if (turn) cout << endl << "*** Гравець 1 - Виграв ***";
			else cout << endl << "*** Гравець 2 - Виграв ***";
			_getch();
			break;
		}
		if (i == 8)
		{
			system("cls");
			printBoard();
			cout << endl << "*** НІЧІЯ ***";
		}

		turn = !turn;
	}
	return 0;
}

void printInputMatrix()
{
	cout << endl << endl << "INPUT MATRIX" << endl;
	cout << " 1 | 2 | 3 " << endl;
	cout << "----------- " << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "----------- " << endl;
	cout << " 7 | 8 | 9 " << endl;
}

void printBoard()
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
	cout << "----------- " << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
	cout << "----------- " << endl;
	cout << " " << board[1][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

int addMark()
{
	for (int i = 0, k = 1; i < 3; i++) {
		for (int j = 0; j < 3; j++, k++) {
			if (k == input)
				if (board[i][j] == ' ') {
					board[i][j] = mark;
					return 1;
				}
				else
				{
					cout << "Invalid Input";
					_getch();
					return 0;
				}
		}
	}
}

int check()
{
	//
	if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark)
		return 1;
	if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark)
		return 1;
	if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark)
		return 1;

	//
	if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark)
		return 1;
	if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark)
		return 1;
	if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark)
		return 1;

	//
	if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
		return 1;
	if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
		return 1;

	return 0;
}