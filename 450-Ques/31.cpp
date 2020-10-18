#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sliding Window
	Time - O(N);
	Space - O(1);
*/ 

int subArraySumK(vector<int>arr, int k) {
	int left = 0;
	int sum = 0;
	int minLength = INT_MAX;
	int right = 0;

	while(right < arr.size()) {
		while(sum <= k) {
			sum += arr[right++];
		}

		while(sum > k) {
			minLength = min(minLength, right - left);
			sum -= arr[left++];
		}
	}
	return minLength;
}

int main() {
	vector<int> arr = {1, 4, 45, 6, 0, 19};
	int  k = 9;

	cout << subArraySumK(arr, k);
	
	return 0;
}