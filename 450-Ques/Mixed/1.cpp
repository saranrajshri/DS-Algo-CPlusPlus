//Allocate minimum pages
#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(n log n);
	Space - O(n);
*/

bool isPossible(vector<int>arr, int m, int minimumPages) {
	int currentCuts = 1;
	int currentSum = 0;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] > minimumPages) return false;
		if(arr[i] + currentSum > minimumPages) {
			currentCuts++;
			currentSum = arr[i];
		}
		if(currentCuts > m) return false;
		else{
			currentSum += arr[i];
		}
	}

	return true;
}

int solve(vector<int>arr, int m) {
	int left = 0;
	int right = accumulate(arr.begin(), arr.end(), 0);
	int result = INT_MAX;

	while(left <= right) {
		int mid = (right - left) + left / 2;
		if(isPossible(arr, m, mid)) {
			result = min(result, mid);
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	return result;
}

int main() {
	vector<int>arr = {12, 34, 67, 90}; 
	cout << solve(arr, 2);
	return 0;	
}
