#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<string>> &grid, int row, int col) {
	if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == "0") return;

	grid[row][col] = "0";

	dfs(grid, row - 1, col);
	dfs(grid, row + 1, col);
	dfs(grid, row, col - 1);
	dfs(grid, row, col + 1);
	
}

int solve(vector<vector<string>> grid) {
	int count = 0;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == "1") {
				dfs(grid, i, j);
				count++;
			}
		}
	}

	return count;
}

int main() {
	vector<vector<string>> grid = {
  {"1","1","0","0","0"},
  {"1","1","0","0","0"},
  {"0","0","1","0","0"},
  {"0","0","0","1","1"}
};
	cout << solve(grid);
	return 0;	
}
