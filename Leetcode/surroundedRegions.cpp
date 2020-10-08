#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>& board, int row, int col) {
    if(row < 0 || row > board.size() -1 || col < 0 || col > board[0].size() - 1 || board[row][col] == 'X' || board[row][col] == '1') return;
    
    if(board[row][col] == 'O') {
        board[row][col] = '1';

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }
}

void solve(vector<vector<char>> & board) {
	int rows = board.size();
	int cols = board[0].size();

	// Traverse the vertical borders
	for(int i = 0; i < rows; i++) {
		if(board[i][0] == 'O') dfs(board, i, 0);
		if(board[i][cols - 1] == '0') dfs(board, i, cols - 1);
	}

	// Traverse the horizontal borders
	for(int j = 1; j < cols - 1; j++) {
		if(board[0][j] == 'O') dfs(board, 0, j);
		if(board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
	}

	// Traverse the matrix and flip the 'O'
	for(int i = 1; i < rows - 1; i++) {
		for(int j = 1; j < cols - 1; j++) {
			if(board[i][j] == 'O') board[i][j] = 'X';
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(board[i][j] == '1') board[i][j] == 'O';
		}	
	}
}

int main() {
	vector<vector<char>>board = {
									{'X', 'X', 'X', 'X'},
									{'X', 'O', 'O', 'X'},
									{'X', 'X', 'O', 'X'},
									{'X', 'O', 'X', 'X'}	
								};	
	solve(board);

	for(auto i : board) {
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}