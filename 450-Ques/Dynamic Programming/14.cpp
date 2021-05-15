#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#define int long long
using namespace std;

int longestCommonSubstr (string s1, string s2, int n, int m) {
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    int result = 0;
    
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(s2[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    
    return result;
}

int32_t main() {
	return 0;	
}