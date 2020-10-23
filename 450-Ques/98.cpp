#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Dynamic Programming
	Time - O(N);
	Space - O(N);
*/ 

int maxNoAdjacent(vector<int> nums) {
	vector<int>dp(nums.size() + 1);

	dp[0] = 0;
	dp[1] = nums[0];

	for(int i = 1; i < nums.size() + 1; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}

	return dp[nums.size()];
}

int main() {
	vector<int> arr = {5, 5, 10, 100, 10, 5};
	cout << maxNoAdjacent(arr);
	return 0;
}