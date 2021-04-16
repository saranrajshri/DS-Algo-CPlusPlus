#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;


int solve(vector<vector<int>> matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	for(int col = n - 2; col >= 0; col--) {
		for(int row = 0; row < m; row++) {
			int right = (col == n - 1) ? 0 : matrix[row][col + 1];
			int rightUp = (col == n - 1 || row == 0) ? 0 : matrix[row - 1][col + 1];
			int rightDown = (col == n - 1 || row == m - 1) ? 0 : matrix[row + 1][col + 1];

			matrix[row][col] = matrix[row][col] + max(right, max(rightUp, rightDown));
		}
	}

	int res = matrix[0][0];

	for(int i = 1; i < m; i++) {
		res = max(res, matrix[i][0]);
	}

	return res;
}

int32_t main() {
	vector<vector<int>> matrix = { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };

    cout << solve(matrix);
	return 0;	
}
