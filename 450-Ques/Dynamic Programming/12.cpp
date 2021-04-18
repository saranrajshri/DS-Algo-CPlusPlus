#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

int solve(vector<int> arr) {
	vector<int> dp;

	for(int x : arr) dp.push_back(x);	

	for(int i = 1; i < arr.size(); i++) {
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i] && dp[j] + arr[i] > dp[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	int res = *max_element(dp.begin(), dp.end());

	return res;
}
int32_t main() {
	vector<int> arr =  {1, 101, 2, 3, 100, 4, 5};
	cout << solve(arr);
	return 0;	
}
