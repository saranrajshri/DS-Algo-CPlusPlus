#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Divide and Conquer
	TIme - O(N);
	Space - O(log N);
*/ 
pair<int, int> minMaxHelper(vector<int> arr, int low, int high) {
	pair<int, int> currentPair;
	
	// if there is only one element
	if(low == high) {
		currentPair.first = arr[low];
		currentPair.second = arr[high];
		return currentPair;
	}

	// If there are two elements
	if(high == low + 1) {
		if(arr[low] < arr[high]) {
			currentPair.first = low;
			currentPair.second= high;
		}else{
			currentPair.first = high;
			currentPair.second = low;
		}
		
		return currentPair;
	}

	// If there are more than two elements
	int mid = low + (high - low) / 2;
	pair<int, int> leftPair = minMaxHelper(arr, low, mid);
	pair<int, int> rightPair = minMaxHelper(arr, mid + 1, high);

	if(leftPair.first < rightPair.first) {
		currentPair.first = leftPair.first;
	}else{
		currentPair.first = rightPair.first;
	}

	if(leftPair.second > rightPair.second) {
		currentPair.second = leftPair.second;
	}else{
		currentPair.second = rightPair.second;
	}

	return currentPair;
}

pair<int, int> findMinMax(vector<int>arr) {
	return minMaxHelper(arr, 0, arr.size() - 1);
}

int main() {
	vector<int> arr =  { 1000, 11, 445, 1, 330, 3000 };
	pair<int, int> res = findMinMax(arr);
	cout << res.first << " " << res.second;
	return 0;
}