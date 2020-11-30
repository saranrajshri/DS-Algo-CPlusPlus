#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<bool>> visited, vector<vector<int>> matrix) {
	if(row < 0|| row >= matrix.size() || col < 0 || col >= matrix[0].size() || visited[row][col] || matrix[row][col] == 0) {
		return false;
	}

	return true;
}

void helper(int row, int col, vector<vector<int>> matrix, vector<vector<bool>> &visited, vector<string>&res, string currentString) {
	if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || visited[row][col] || matrix[row][col] == 0) {
		return;
	}	

	if(row == matrix.size() - 1 && col == matrix[0].size() - 1) {
		res.push_back(currentString);
		return;
	}

	visited[row][col] = true;

	if(isSafe(row + 1, col, visited, matrix)) {
		currentString += 'D';
		helper(row + 1, col, matrix, visited, res, currentString);

		currentString.pop_back();
	}

	if(isSafe(row, col + 1, visited, matrix)) {
		currentString += 'R';
		helper(row, col + 1,  matrix, visited, res, currentString);

		currentString.pop_back();
	}
	
	if(isSafe(row, col - 1, visited, matrix)) {
		currentString += 'L';
		helper(row, col - 1,  matrix, visited, res, currentString);

		currentString.pop_back();
	}
	
	if(isSafe(row - 1, col, visited, matrix)) {
		currentString += 'U';
		helper(row - 1, col,  matrix, visited, res, currentString);

		currentString.pop_back();
	}

	visited[row][col] = false;

}

vector<string> solve(vector<vector<int>> matrix) {
	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
	vector<string> res;
	helper(0, 0, matrix, visited, res, "");

	return res;
}

int main() {
	vector<vector<int>> matrix =  { { 1, 0, 0, 0, 0 }, 
                        { 1, 1, 1, 1, 1 }, 
                        { 1, 1, 1, 0, 1 }, 
                        { 0, 0, 0, 0, 1 }, 
                        { 0, 0, 0, 0, 1 } };
	vector<string> res = solve(matrix);

	for(string s : res) {
		cout << s << " ";
	}                      
	return 0;	
}
