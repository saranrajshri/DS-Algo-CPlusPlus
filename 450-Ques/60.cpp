#include<bits/stdc++.h>
using namespace std;


/*
	Approach - Dynamic Programming
	Time - O(nm);
	Space - O(nm);
*/ 

int editDistance(string s1, string s2) {
	vector<vector<int>> dp(s2.size() + 1, vector<int>(s1.size() + 1));

	for(int i = 0; i < s2.size() + 1; i++) {
		for(int j = 0; j < s1.size() + 1; j++) {
			dp[0][j] = j;
		}
		dp[i][0] = i;
	}
	
	for(int i = 1; i < s2.size() + 1; i++) {
		for(int j = 1; j < s1.size() + 1; j++) {
			if(s2[i - 1] == s1[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	return dp[s2.size()][s1.size()];
}

int main() {
	string s1 = "geek";
	string s2 = "gesek";

	cout << editDistance(s1, s2);

	return 0;
}
