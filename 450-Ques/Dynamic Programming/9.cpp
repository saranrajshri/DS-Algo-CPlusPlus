#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

int solve(string strOne, string strTwo) {
	vector<vector<int>> dp(strOne.size() + 1, vector<int>(strTwo.size() + 1));

	for(int i = 1; i < strTwo.size() + 1; i++) {
		for(int j = 1; j < strOne.size() + 1; j++) {
			if(strTwo[i] == strOne[j] && i != j) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);;
			}
		}
	}

	return dp[strTwo.size()][strOne.size()];
}

int32_t main() {
	string strOne = "aabbccdd";
	string strTwo = "baddccbb";
	cout << solve(strOne, strTwo);
	return 0;	
}
