#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>board) {
	return (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == -1);
}

bool helper(vector<vector<int>>&board, int row, int col, int move, vector<int> xMove, vector<int> yMove) {
	if(move == board.size() * board.size()) {
		return true;
	}

	for(int k = 0; k < 8; k++) {
		int nextRow = row + xMove[k];
		int nextCol = col + yMove[k];

		if(isSafe(nextRow, nextCol, board)) {
			board[nextRow][nextCol] = move;
			if(helper(board, nextRow, nextCol, move + 1, xMove, yMove)) return true;
			else {
				board[nextRow][nextCol] = -1;
			} 
		}
		
	}

	return false;
}

void printBoard(vector<vector<int>>board) {
	for(auto arr : board) {
		for(int x : arr) {
			cout << x << " ";
		}
		cout << endl;
	}
}

void solveKnightTour() {
	int n = 8;
	vector<vector<int>> board(n, vector<int>(n, -1));
	vector<int> xMove = { 2, 1, -1, -2, -2, -1, 1, 2 };
	vector<int> yMove = { 1, 2, 2, 1, -1, -2, -2, -1};

	board[0][0] = 1;

	helper(board, 0, 0, 1, xMove, yMove);

	printBoard(board);
}

int main() {
	solveKnightTour();
	return 0;
}