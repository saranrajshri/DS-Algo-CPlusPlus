#include<bits/stdc++.h>
using namespace std;

int solve(string str1, string str2) {
	vector<vector<int>> dp(str2.size() + 1, vector<int>(str1.size() + 1));

	for(int i = 0; i < str2.size() + 1; i++) {
		for(int j = 0; j < str1.size() + 1	; j++) {
			if(i == 0) {
				dp[i][j] = j;
			}

			if(j == 0) {
				dp[i][j] = i;
			}

			if(str2[i - 1] == str1[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j -1])) + 1;
			}
		}
	}

	return dp[str2.size()][str1.size()];
}

int main() {
	string str1 = "geek";
	string str2 = "gesek";

	cout << solve(str1, str2) << endl;
	return 0;
}