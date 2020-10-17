#include<bits/stdc++.h>
using namespace std;

// Time - o(N);
// Space - O(1);

int maxElement(vector<int>arr) {
	if(arr.size() == 0) return -1;
	int maximum = arr[0];

	for(int i = 1; i < arr.size(); i++) {
		maximum = max(maximum, arr[i]);
	}

	return maximum;
}

int minElement(vector<int>arr) {
	if(arr.size() == 0) return -1;
	int minimum = arr[0];

	for(int i = 1; i < arr.size(); i++) {
		minimum = min(minimum, arr[i]);
	}

	return minimum;
}

int main() {
	vector<int>arr = {1, 2, 3, 4, 5};
	cout << minElement(arr) << endl;
	cout << maxElement(arr) << endl;
	return 0;
}