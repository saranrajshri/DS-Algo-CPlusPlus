#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	return dp[m - 1][n - 1];
}

int main() {
	int m = 3, n = 7;
	cout << solve(m, n);
	return 0;	
}
