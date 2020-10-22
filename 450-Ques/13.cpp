#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Kadane's Algorithm
	time - O(N);
	Space -O(1);
*/

int largestSubArray(vector<int>arr){
	int maxEndHere = arr[0];
	int maxSoFar = arr[0];

	for(int i = 0; i < arr.size(); i++) {
		maxEndHere = max(arr[i], maxEndHere + arr[i]);
		maxSoFar = max(maxSoFar, maxEndHere);
	}

	return maxSoFar;
}


int main() {
	vector<int>arr = {1, 2, 3, -10, 1};
	cout <<  largestSubArray(arr);

	return 0;
}