#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int minPrice = arr[0];
	int maxProfit = INT_MIN;

	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] < minPrice) minPrice = arr[i];
		else {
			maxProfit = max(maxProfit, arr[i] - minPrice);
		}
	}

	return maxProfit;
}

int main() {
	vector<int> arr = {7,1,5,3,6,4};
	cout << solve(arr);
	return 0;	
}
