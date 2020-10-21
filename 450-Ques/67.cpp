#include<bits/stdc++.h>
using namespace std;


/*
	Approach - DFS + Backtracking
	Time - O(N ^ 2);
	Space - O(N).
*/ 


bool dfs(vector<vector<char>> board, int row, int col, int index, string str) {
	
	if(index == str.size())  return true;

	if(row < 0 || row >= board.size() || col < 0 || col >= board[row].size() ||  board[row][col] == ' ' || board[row][col] != str[index]) return 0;

	char temp = board[row][col];

	board[row][col] = ' ';
	
	bool isFound = 
	 dfs(board, row - 1, col, index + 1, str) ||
	 dfs(board, row + 1, col, index + 1, str) ||
	 dfs(board, row, col - 1, index + 1, str) ||
	 dfs(board, row, col + 1, index + 1, str);

	board[row][col] = temp;

	return isFound;
}

bool countWords(vector<vector<char>> board, string str) {

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			if(board[i][j] == str[0] && dfs(board, i, j, 0, str)) {
				return true;
			}		
		}
	}
	return false;
}

int main() {

	vector<vector<char>> board = {  {'B','B','A','B','B','M'}, 
	   {'C','B','M','B','B','A'},  
	   {'I','B','A','B','B','G'},  
	   {'G','O','Z','B','B','I'},  
	   {'A','B','B','B','B','C'},  
	   {'M','C','I','G','A','M'},
	};
	string str = "MAGIC";

	if(countWords(board, str)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}