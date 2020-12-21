#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&grid) {
	queue<pair<int, int>> q;
	int fresh = 0;
	int ans = -1;
	vector<int> dir = {-1,0,1,0,-1};


	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			if(grid[i][j] == 2) {
				q.push(make_pair(i, j));
			}else if(grid[i][j] == 1) {
				fresh++;
			}
		}
	}


	while(!q.empty()) {
		int currentSize = q.size();
		while(currentSize--) {
			pair<int, int> currentCell = q.front();
			q.pop();

			for(int i = 0; i < 4; i++) {
				int newX = currentCell.first + dir[i];
				int newY = currentCell.second + dir[i + 1];

				if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1) {
					grid[newX][newY] = 2;
					q.push(make_pair(newX, newY));
					fresh--;
				}	
			}
		}
		ans++;
	}

	if(fresh > 0) return -1;
	if(ans == -1)  return 0;

	return ans;
}


int main() {
	vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};

	cout << solve(grid);
	return 0;	
}
