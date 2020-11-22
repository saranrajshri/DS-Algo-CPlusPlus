#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int n, int currentIndex) {
	int largestIndex = currentIndex;
	int leftIndex = 2 * currentIndex + 1;
	int rightIndex = 2 * currentIndex + 2;

	if(leftIndex < n && arr[leftIndex] > arr[currentIndex]) largestIndex = leftIndex;
	if(rightIndex < n && arr[rightIndex] > arr[currentIndex]) largestIndex = rightIndex;

	if(largestIndex != currentIndex) {
		swap(arr[largestIndex], arr[currentIndex]);

		heapify(arr, n, largestIndex);
	}
}

void heapSort(vector<int>arr) {
	for(int i = arr.size() / 2 - 1; i >= 0; i--) {
		heapify(arr, arr.size(), i);
	}

	for(int i = arr.size() - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}

	for(int x : arr) cout << x << " ";
}

int main() {
	vector<int> arr =  {12, 11, 13, 5, 6, 7};
	heapSort(arr);
	return 0;	
}
