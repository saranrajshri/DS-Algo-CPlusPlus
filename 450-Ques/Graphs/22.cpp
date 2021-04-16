#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;


pair<int, int> coordinates(int x, int n) {
        int r = n - (x-1)/n -1;
        int c = (x-1)%n;
        if(r%2==n%2)
            return {r,n-c-1};
        return {r, c};
    }


int solve(vector<vector<int>> matrix) {
	int steps = 0;	
	int n= matrix.size();

	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix.size(), false));
	visited[n - 1][0] = true;
	queue<int>q;
	q.push(1);

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			int x = q.front();
			if(x == n * n) return steps;
			q.pop();

			for(int j = 1; j < 7; j++){
				if(j + x > n * n) break;
				pair<int, int> newPos = coordinates(j + x, n);
				if(visited[newPos.first][newPos.second]) continue;

				visited[newPos.first][newPos.second] = true;

				if(matrix[newPos.first][newPos.second] != -1) {
					q.push(matrix[newPos.first][newPos.second]);
				}else{
					q.push(j + x);
				}
			}

		}

		steps++;
	}

	return steps;
}


int32_t main() {
	vector<vector<int>> matrix = {
									{-1,-1,-1,-1,-1,-1},
									{-1,-1,-1,-1,-1,-1},
									{-1,-1,-1,-1,-1,-1},
									{-1,35,-1,-1,13,-1},
									{-1,-1,-1,-1,-1,-1},
									{-1,15,-1,-1,-1,-1}};

    cout << solve(matrix);										
	return 0;	
}
