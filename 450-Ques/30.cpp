#include<bits/stdc++.h>
using namespace std;


/*	
	https://www.geeksforgeeks.org/chocolate-distribution-problem/
	Time - O(N log N);
	Space - O(1);
*/ 
int minDiff(vector<int>arr, int m) {
	sort(arr.begin(), arr.end());

	int minDiff = INT_MAX;

	for(int i = 0; i < m - 1; i++) {
		minDiff = min(minDiff, arr[i + m - 1] - arr[i]);
	}

	return minDiff;
}

int main() {
	vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
	int m = 5;

	cout << minDiff(arr, m);
	return 0;
}