#include<bits/stdc++.h>
using namespace std;

/*
	Approach 
	1. Keep track of the minPrice, If there is a new minPrice, then update it.
	2. If there is a value greater than the minPrice, so that means we can sell the stock .
	3. Keep a maxProfit variable to keep track of the maxProfit;

	Time - O(N);
	Space - O(1);

*/ 

int bestTimeToBuyAndSellStock(vector<int>arr) {
	int minPrice = INT_MAX;
	int maxProfit = 0;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] < minPrice) {
			minPrice = arr[i];
		}else{
			maxProfit = max(maxProfit, arr[i] - minPrice);
		}
	}

	return maxProfit;
}

int main() {
	vector<int>arr = {7,6,4,3,1};
	cout << bestTimeToBuyAndSellStock(arr);
	
	return 0;
}