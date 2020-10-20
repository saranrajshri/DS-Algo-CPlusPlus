#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Dynamic Programming

	Similar to Longest Common Subsequence Problem
	
	Time - O(N ^ 2);
	Space - O(N ^ 2)
*/ 

int longestRepeatingSubSequence(string s) {
	vector<vector<int>>dp(s.size() + 1, vector<int>(s.size() + 1));

	for(int i = 1; i < s.size() + 1; i++) {
		for(int j = 1; j < s.size() + 1; j++) {
			if(s[i - 1] == s[j - 1] && i != j) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	} 

	return dp[s.size()][s.size()];
}

int main() {
	string s = "axxxy";
	cout << longestRepeatingSubSequence(s);
	return 0;
}
