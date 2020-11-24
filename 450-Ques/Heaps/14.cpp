#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int n, int currentIndex) {
	int largestIndex = currentIndex;
	int leftIndex = currentIndex * 2 + 1;
	int rightIndex = currentIndex * 2 + 2;

	if(leftIndex < arr.size() && arr[leftIndex] > arr[largestIndex]) largestIndex = leftIndex;
	if(rightIndex < arr.size() && arr[rightIndex] > arr[largestIndex]) largestIndex = rightIndex;

	if(largestIndex != currentIndex) {
		swap(arr[largestIndex], arr[currentIndex]);

		heapify(arr, n, largestIndex);
	}
}

vector<int> solve(vector<int>arr) {
	for(int i = arr.size() / 2 - 1; i >= 0; i--) {
		heapify(arr, arr.size(), i);
	}

	return arr;
}

int main() {
	vector<int>arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	vector<int>res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}
