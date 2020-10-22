#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Dynamic Programming
	Time - O(mn);
	Space - O(mn)
*/ 

int longestCommonSubsequence(string s1, string s2) {
	vector<vector<int>> dp(s2.size() + 1, vector<int>(s1.size() + 1));

	for(int i = 1; i < s2.size() + 1; i++) {
		for(int j = 1; j < s1.size() + 1; j++){
			if(s2[i - 1] == s1[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[s2.size()][s1.size()];
}

int main() {
	string s1 = "ABCDGH";
	string s2 = "AEDFHR";

	cout << longestCommonSubsequence(s1, s2);
	return 0;
}
