#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<string>> board, int row, int col, string val) {

	int newRow = row - row % 3;
	int newCol = col - col % 3;

	for(int i = 0; i < 9; i++) {
		if(board[i][col] == val) return false;
	}

	for(int i = 0; i < 9; i++) {
		if(board[row][i] == val) return false;
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[newRow + i][newCol + j] == val) return false;
		}
	} 

	return true;
}

bool solveSudokuHelper(vector<vector<string>> &board, int row, int col) {
	cout << row << "  " << col << endl;
	if(row == 9) return true;
	if(col == 9) return solveSudokuHelper(board, row + 1, 0);

	if(board[row][col] != ".") solveSudokuHelper(board, row, col + 1);

	for(char c = '1'; c <= '9'; c++) {
		if(isSafe(board, row, col, to_string(c))) {
			board[row][col] = to_string(c);
			if(solveSudokuHelper(board, row, col + 1)) return true;
			board[row][col] = ".";
		}
	}

	return false;
}

void solveSudoku(vector<vector<string>> &board) {
	solveSudokuHelper(board, 0, 0);
}

int main() {
	vector<vector<string>> board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
	solveSudoku(board);
	for(auto array : board) {
		for(string x : array) cout << x << " ";
		cout << endl;
	}

	return 0;
}