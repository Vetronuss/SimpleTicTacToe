#include <iostream>
using namespace std;

void drawBoard(char board[3][3])
{
	system("clear");
	for (int x = 0; x < 3; x++)
	{
		cout << " ";
		for (int y = 0; y < 3; y++)
		{
			if (y < 2)
				cout << board[x][y] << " | ";
			else
				cout << board[x][y];
		}
		cout << endl;
		if (x < 2)
			cout << "-----------\n";
		}

}


int main() {

	//3x3 array of characters
	//each spot will be a X, O or empty
	char board[3][3] = 
	{
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '}
	};

	char turn = 'X';
	char winner = ' ';

	//a loop that will keep going until someone wins
	while (winner == ' ')
	{
		//draw the board
		system("clear");
		for (int x = 0; x < 3; x++)
		{
			cout << " ";
			for (int y = 0; y < 3; y++)
			{
				if (y < 2)
					cout << board[x][y] << " | ";
				else
					cout << board[x][y];
			}
			cout << endl;
			if (x < 2)
				cout << "-----------\n";
		}

		//a loop to keep asking the user to pick a move until they pick one that isnt taken
		int input = 0;
		do
		{
			cout << "Pick a move 1 - 9 that isnt taken:\n";
			cin >> input;
			input--;
		}while (board[input/3][input%3] != ' ');
		
		
		board[input/3][input%3] = turn;
		
		//check for winner by scanning board for 3 in a row
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (y == 1)
				{
					if (board[x][y+1] == board[x][y] && board[x][y-1] == board[x][y])
					{
						winner = board[x][y];
					}
				}
				if (x == 1)
				{
					if (board[x+1][y] == board[x][y] && board[x-1][y] == board[x][y])
					{
						winner = board[x][y];
					}
				}
				if (x == 1 && y == 1)
				{
					
					if (board[x+1][y+1] == board[x][y] && board[x-1][y-1] == board[x][y])
					{
						winner = board[x][y];
					}
					if (board[x-1][y+1] == board[x][y] && board[x+1][y-1] == board[x][y])
					{
						winner = board[x][y];
					}
				}
			}
		}

		//switch turns
		if (turn == 'X')
			turn = 'O';
		else
			turn = 'X';
	}

	//anounce winner
	drawBoard(board);
	cout << winner << "'s Win!\n";
	
	char answer;
	cout << "Play Again? (y/n)\n";
	cin >> answer;
	
	if (answer == 'y'){
		main();
	}

	return 0;
}