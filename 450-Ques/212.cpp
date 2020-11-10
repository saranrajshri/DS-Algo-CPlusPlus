#include<bits/stdc++.h>
using namespace std;

vector<int> xMove = {0, 1, -1, 0};
vector<int> yMove = {1, 0, 0, -1};

bool isValid(vector<vector<int>> matrix, int row, int col) {
	if(row >= 0 && row < matrix.size() &&col >= 0 && col < matrix[row].size()) return true;
	return false;
}

bool isSafe(vector<vector<int>> matrix, int x, int y, vector<vector<bool>> visited){ 
    if (matrix[x][y] == 0 || visited[x][y]) 
        return false; 
    return true; 
}

void markUnSafeCells(vector<vector<int>> &matrix) {
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			if(matrix[i][j] == 0) {
				for(int k = 0; k < 4; k++) {
					if(isValid(matrix, i + xMove[k], j + yMove[k])) {
						matrix[i][j] = -1;
					}
				}
			}
		}
	}


	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			if(matrix[i][j] == -1) matrix[i][j] = 0;
		}
	}
}

void helper(vector<vector<int>> matrix, int row, int col, int &minDistance, int currentDistance, vector<vector<bool>>&visited) {
	if(col == matrix[row].size() - 1) {
		minDistance = min(minDistance, currentDistance);
		return;
	}

	if(currentDistance > minDistance) return;
	
	visited[row][col] = true;
	for(int k = 0; k < 4; k++) {
		if(isValid(matrix, row + xMove[k], col + yMove[k]) && isSafe(matrix, row + xMove[k], col + yMove[k], visited)) {
			helper(matrix, row + xMove[k], col + yMove[k], minDistance, currentDistance + 1, visited);
		}
	}
	visited[row][col] = false;
}

void solve(vector<vector<int>> &matrix) {
	markUnSafeCells(matrix);
	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));

	int minDistance = INT_MAX;


	for(int row = 0; row < matrix.size(); row++) {
		if(matrix[row][0] == 1) {
			helper(matrix, row, 0, minDistance, 0, visited);	
			if(minDistance == matrix[0].size() - 1) {
				break;
			}
		}
	}

	cout << minDistance << endl;
}

int main() {
	vector<vector<int>> matrix = { 
					        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
					        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 }, 
					        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
					        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } 
					    }; 
  	solve(matrix);
	return 0;
}