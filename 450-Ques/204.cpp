#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(3^N), N - Number of elements in the matrix
	Space - O(3^N), N - Number of elements in the matrix
*/		

bool isSafe(vector<vector<int>> matrix, int row, int col, vector<vector<bool>> visited) {
	if(row < 0 || row >= matrix.size() || col < 0 || col > matrix[row].size() || visited[row][col] || matrix[row][col] == 0) return false;

	return true;
}

void findPathsHelper(vector<vector<int>> matrix, int row, int col, vector<char>& currentPath, vector<vector<bool>> visited, vector<vector<char>>&res) {
	if(row < 0 || row >= matrix.size() || col < 0 || visited[row][col] || col >= matrix[row].size()) return;

	if(row == matrix.size() - 1 && col == matrix[row].size() - 1) {
		res.push_back(currentPath);
		return;
	}


	visited[row][col] = true;

	if(isSafe(matrix, row + 1, col, visited)) {
		currentPath.push_back('D');
		findPathsHelper(matrix, row + 1, col, currentPath, visited, res);
		currentPath.pop_back();
	}

	if(isSafe(matrix, row, col - 1, visited)) {
		currentPath.push_back('L');
		findPathsHelper(matrix, row, col - 1, currentPath, visited, res);
		currentPath.pop_back();
	}
	
	if(isSafe(matrix, row, col + 1, visited)) {
		currentPath.push_back('R');
		findPathsHelper(matrix, row, col + 1, currentPath, visited, res);
		currentPath.pop_back();
	}

	if(isSafe(matrix, row - 1, col, visited)) {
		currentPath.push_back('U');
		findPathsHelper(matrix, row - 1, col, currentPath, visited, res);
		currentPath.pop_back();
	}

	visited[row][col] = false;
}


vector<vector<char>> findPaths(vector<vector<int>> matrix) {
	vector<vector<char>>res;
	vector<char>currentPath;
	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

	findPathsHelper(matrix, 0, 0, currentPath, visited, res);

	return res;
}

int main() {
	vector<vector<int>> matrix = { { 1, 0, 0, 0, 0 }, 
		                        { 1, 1, 1, 1, 1 }, 
		                        { 1, 1, 1, 0, 1 }, 
		                        { 0, 0, 0, 0, 1 }, 
		                        { 0, 0, 0, 0, 1 } }; 
	vector<vector<char>> res = findPaths(matrix);
	
	for(vector<char> s: res) {
		for(char x : s) cout << x << " ";
		cout << endl;
	}
	return 0;
}