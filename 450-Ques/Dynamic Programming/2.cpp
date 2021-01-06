#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>weights, vector<int> values, int capacity) {
	vector<vector<int>> dp(weights.size() + 1, vector<int>(capacity + 1));

	for(int currentWeightIndex = 1; currentWeightIndex < weights.size() + 1; currentWeightIndex++) {
		for(int currentCapacity = 1; currentCapacity < capacity + 1; currentCapacity++) {
			if(weights[currentWeightIndex - 1]  <= currentCapacity) {
				dp[currentWeightIndex][currentCapacity] = max(values[currentWeightIndex - 1] + dp[currentWeightIndex - 1][currentCapacity - weights[currentWeightIndex - 1]], dp[currentWeightIndex - 1][currentCapacity]); 
			}else{
				dp[currentWeightIndex][currentCapacity] = dp[currentWeightIndex - 1][currentCapacity];
			}			
		}
	}

	return dp[weights.size()][capacity];
}

int main() {
	vector<int> weights = { 1, 2, 3 }; 
	vector<int> values = {10, 15, 40};
	int capacity = 6;

	cout << solve(weights, values, capacity) << endl;
	return 0;	
}
