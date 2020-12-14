#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	vector<int> left(arr.size());
	vector<int> right(arr.size());

	left[0] = arr[0];
	for(int i = 1; i < arr.size(); i++) {
		left[i] = max(left[i - 1], arr[i]);
	}

	right[arr.size() - 1] = arr[arr.size() - 1];

	for(int i = arr.size() - 2; i >= 0; i--) {
		right[i] = max(right[i + 1], arr[i]);
	}

	int water = 0;
	for(int i = 0; i < arr.size(); i++) {
		water += min(left[i], right[i]) - arr[i];
	}

	return water;
}

int main() {
	vector<int>arr = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << solve(arr);

	return 0;	
}

