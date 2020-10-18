#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Similar to Kadane's Algorithm
	Time - O(N);
	Space - O(1);

*/ 

int maximumProductSubArray(vector<int>arr) {
	int minVal = arr[0];
	int maxVal = arr[0];
	int maxProd = INT_MIN;

	for(int i = 1; i < arr.size(); i++) {
		
		// When mutiplied by -ve number, maxVal becomes minimum and minVal becomes maximum
		if(arr[i] < 0) {
			swap(minVal, maxVal);
		}

		maxVal = max(arr[i], maxVal * arr[i]);
		minVal = min(arr[i], minVal * arr[i]);

		maxProd = max(maxProd, maxVal);
	}

	return maxProd;
}

int main() {
	vector<int>arr = { -1, -3, -10, 0, 60 };
	cout << maximumProductSubArray(arr);
	return 0;
}