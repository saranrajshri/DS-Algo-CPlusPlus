#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> matrix) {
	queue<pair<int, int>> q;

	vector<int> dir={-1,0,1,0,-1};

	int fresh = 0;
	int ans = -1;

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			if(matrix[i][j] == 2) {
				q.push(make_pair(i, j));
			}
			else if(matrix[i][j] == 1) {
				fresh++;
			}
		}
	}


	while(!q.empty()) {
		int currentQSize = q.size();
		while(currentQSize--) {
			pair<int, int> currentCell = q.front();
			q.pop();

			for(int i = 0; i < 4; i++) {
				int newX = currentCell.first + dir[i];
				int newY = currentCell.second + dir[i + 1];

				if(newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size() && matrix[newX][newY] == 1) {
					matrix[newX][newY] = 2;
					q.push(make_pair(newX, newY));
					fresh--;
				}
			}
		}
		ans++;		
	}

	if(fresh > 0) return -1;
	if(ans == -1) return 0;

	return ans;
}

int main() {
	vector<vector<int>> matrix = {{2,1,1},{0,1,1},{1,0,1}};
	cout << solve(matrix) << endl;
	return 0;	
}
