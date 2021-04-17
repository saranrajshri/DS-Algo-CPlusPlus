#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

int solve(string strOne, string strTwo, string strThree) {
	vector<vector<vector<int>>> dp(strOne.size() + 1, vector<vector<int>>(strTwo.size() + 1, vector<int>(strThree.size() + 1)));

	for(int i = 1; i < strThree.size() + 1; i++) {
		for(int j = 1; j < strTwo.size() + 1; j++) {
			for(int k = 1; k < strOne.size() + 1; k++) {
				if(strThree[i] == strTwo[j] == strOne[i]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}else{
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}

	return dp[strThree.size()][strTwo.size()][strOne.size()];
}

int32_t main() {
	string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";
  
  	cout << solve(X, Y, Z);
	return 0;	
}
