#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

int solve(int n, int k) {
	vector<int> dp(n + 1);
	dp[1] = k;
	dp[2] = k + k * (k - 1);

	for(int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
	}

	return dp[n];
}

int32_t main() {
	int n = 3;
	int k = 2;
	cout << solve(n, k);
	return 0;	
}
