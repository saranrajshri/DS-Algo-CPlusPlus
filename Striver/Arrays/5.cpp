#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int maxEndHere = arr[0];
	int maxSoFar = arr[0];

	for(int i = 1; i < arr.size(); i++) {
		maxEndHere = max(arr[i], maxEndHere + arr[i]);
		maxSoFar = max(maxSoFar, maxEndHere);
	}

	return maxSoFar;
}

int main() {
	vector<int>arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout << solve(arr);
	return 0;	
}

