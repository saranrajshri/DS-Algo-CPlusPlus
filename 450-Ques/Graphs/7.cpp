#include<bits/stdc++.h>
using namespace std;

struct cell {
	int x;
	int y;
	int dist;

	cell(){};
	cell(int x, int y, int dist) :x(x), y(y), dist(dist) {}
};

bool isSafe(int row, int col, int n) {
	if(row < 0 || row >= n || col < 0 || col >= n) return false;
	return true;
}

int solve(vector<int> source, vector<int> target, int n) {
	vector<int> dx = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    vector<int> dy = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

    queue<cell>q;

    q.push(cell(source[0], source[1], 0));

    vector<vector<bool>> visited(n, vector<bool>(n , false));

    visited[source[0]][source[1]] = true;
    
    cell currentCell;

    while(!q.empty()) {
    	currentCell = q.front();
    	q.pop();

    	if(currentCell.x == target[0] && currentCell.y == target[1]) {
    		return currentCell.dist;
    	}

    	for(int i = 0; i < 8; i++) {
    		int newX = currentCell.x + dx[i];
    		int newY = currentCell.y + dy[i];

    		if(isSafe(newX, newY, n) && visited[newX][newY] == false) {
    			visited[newX][newY] = true;
    			q.push(cell(newX, newY, currentCell.dist + 1));
    		}
    	}
    }

    return -1;
}

int main() {
	int n = 30;
	vector<int> source = { 1, 1 }; 
	vector<int> target = { 30, 30 };
	cout << solve(source, target, n);
	return 0;	
}
