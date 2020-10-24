#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>arr) {
	int left = 0;
	int right = arr.size() - 1;

	while(left < right) {	
		int mid = left + (right - left) / 2;

		if(arr[mid] > arr[right]) left = mid + 1;
		else right = mid;
	}

	return left;
}

int main() {
	vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	cout << pivotIndex(arr);
	return 0;
}