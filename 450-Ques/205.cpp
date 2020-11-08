#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> board) {
	for(auto array : board) {
		for(int x : array) {
			cout << x << " ";
		}
		cout << endl;
	}
}

bool isSafe(vector<vector<int>> board, int row, int col) {
	for(int i = 0; i < col; i++) {
		if(board[row][i]) return false;
	}

	for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if(board[i][j]) return false;
	}

	for(int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
		if(board[i][j]) return false;
	}	

	return true;
}

bool nQueenHelper(vector<vector<int>> board, int col) {
	if(col == board.size()) {
		printBoard(board);
		cout << "======" << endl; 
		return true;
	}

	bool res = false;
	for(int row = 0; row < board.size(); row++) {
		if(isSafe(board, row, col)) {
			board[row][col] = 1;

			res = nQueenHelper(board, col + 1) || res;

			board[row][col] = 0;
		}
	}
	return res;
}

void nQueen(int n) {
	vector<vector<int>> board(n, vector<int>(n, 0));

	if(nQueenHelper(board, 0) == false) {
		cout << "No Solution" << endl;
	}
}

int main() {
	int n = 8;
	nQueen(n);
	return 0;
}