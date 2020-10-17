#include<bits/stdc++.h>
using namespace std;

/*
	Dynamic Programming
	Time - O(N ^ 2);
	Space - 0(N);
*/ 

int minJumps(vector<int>arr) {
	vector<int>dp(arr.size() + 1, INT_MAX);
	dp[0] = 0;

	for(int i = 1; i < arr.size(); i++) {
		for(int j = 0; j < i; j++) {
			if(i <= j + arr[j]) {
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	return dp[arr.size() - 1];
}



int main() {
	vector<int>arr = {1, 5, 8, 9, 7, 1};
	cout << minJumps(arr);
	return 0;
}