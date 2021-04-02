#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int currentIndex) {
	int largestIndex = currentIndex;
	int leftIndex = (currentIndex * 2) + 1;
	int rightIndex = (currentIndex * 2) + 2;

	if(leftIndex < arr.size() && arr[leftIndex] > arr[largestIndex]) {
		largestIndex = leftIndex;
	}

	if(rightIndex < arr.size() && arr[rightIndex] > arr[largestIndex]) {
		largestIndex = rightIndex;
	}

	if(currentIndex	 != largestIndex) {
		swap(arr[largestIndex], arr[currentIndex]);

		heapify(arr, largestIndex);
	}
}


void heapify(vector<int>&arr, int currentIndex) {
	int smallestIndex = currentIndex;
	int leftIndex = 2 * currentIndex + 1;
	int rightIndex = 2 * currentIndex + 2;

	if(leftIndex < arr.size()  && arr[leftIndex] < arr[smallestIndex]) {
		smallestIndex = leftIndex;
	}

	if(rightIndex < arr.size()  && arr[rightIndex] < arr[smallestIndex]) {
		smallestIndex = rightIndex;
	}

	if(smallestIndex != currentIndex) {
		swap(arr[smallestIndex], arr[currentIndex]);

		heapify(arr, smallestIndex);
	}
}

void solve(vector<int>&arr) {
	int midIndex = (arr.size() / 2) - 1;
 
	for(int i = midIndex; i >= 0; i--) {
		heapify(arr, i);
	}

	for(int x : arr) cout << x << " ";

}

int main() {
	vector<int>arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
	solve(arr);
	
	return 0;	
}
