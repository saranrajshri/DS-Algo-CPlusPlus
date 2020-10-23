#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Binary Search
	Time - O(log N);
	Space - O(1);	
*/		


int lowerBound(vector<int>arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(arr[mid] < target) left = mid + 1;
		else right = mid - 1; 
	} 

	return left;
}

vector<int>firstAndLastOccurence(vector<int>arr, int target) {
	int leftIndex = lowerBound(arr, target);
	int rightIndex =  lowerBound(arr, target + 1) - 1;

	if(leftIndex < rightIndex && arr[leftIndex] == arr[rightIndex]) {
		return vector<int>{leftIndex, rightIndex};
	}
 
 	return vector<int>{-1 , -1};
}

int main() {
	vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
	vector<int>res = firstAndLastOccurence(arr, 5);
	cout << res[0] << " " << res[1];
	return 0;
}
