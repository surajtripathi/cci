#include <iostream>

using namespace std;

int MAX_ROW = 3;
int MAX_COL = 3;

class TicTacToe {
	char mattrix[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int count = 0;
	void place(int row , int col, char c) {
		mattrix[row][col] = c;
		count++;
	}
	bool isEmpty(int row, int col) {
		return (mattrix[row][col] == ' ' ? true : false);
	}
	bool isFull() {
		return (count == (MAX_ROW * MAX_COL) ? true : false);
	}
	bool done() {
		if(isFull())
			return true;
		
		for(int row=0; row<3; row++)
			if(mattrix[row][0] != ' ' && mattrix[row][0] == mattrix[row][1] && mattrix[row][1] == mattrix[row][2])
				return true;
		for(int col=0; col<3; col++)
			if(mattrix[0][col] != ' ' && mattrix[0][col] == mattrix[1][col] && mattrix[1][col] == mattrix[2][col])
				return true;
		if(mattrix[0][0] != ' ' && mattrix[0][0] == mattrix[1][1] && mattrix[1][1] == mattrix[2][2])
			return true;
		if(mattrix[0][2] != ' ' && mattrix[0][2] == mattrix[1][1] && mattrix[1][1] == mattrix[2][0])
			return true;
		
		return false;
	}

	void printTicTacToe() {
		for(int row=0; row<MAX_ROW; row++) {
			cout << mattrix[row][0] << "|" << mattrix[row][1] << "|" << mattrix[row][2] << endl;
			if(row!=2) cout << "-----" << endl;
 		}
	}
	public:
	void play() {
		int row, col;
		do {
			cin >> row;
			cin >> col;
			if(isEmpty(row, col)) {
				if(!isFull()) { 
					place(row, col, 'X');
					printTicTacToe();
				} else {
					cout << "Game finished\n";
				}
			} else {
				cout << "Location is full" << endl;
			}
		} while(!done());
	}
};

int main() {
	TicTacToe ttt;
	ttt.play();
	return 0;
}