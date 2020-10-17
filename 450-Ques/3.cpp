#include<bits/stdc++.h>
using namespace std;

// Approach 1
/*
	Sort the array;
	Travese the array till the index k
	When the pointer reaches the index k - 1, return the element;
	Time - O(N long N);
	Space - O(1)
*/


/*
	Approach 2
	Use Quick Select Algorithm
*/	


// Approach 3

// Time - O(N);
// Space - O(N);	

int kthLargest(vector<int>arr, int k){
	priority_queue<int, vector<int>> minHeap;

	// Push all the elements in the heap;
	// when the size of the heap exceeds the value k;
	// Then pop the top element in the heap;
	// Do this until the size of the heap is <= k;

	for(int i = 0; i < arr.size(); i++) {
		minHeap.push(arr[i]);
		
		while(minHeap.size() > k) {
			minHeap.pop();
		}
	}

	return minHeap.top();
}

int kthSmallest(vector<int>arr, int k){
	priority_queue<int, vector<int>, greater<int>> maxHeap;

	// Push all the elements in the heap;
	// when the size of the heap exceeds the value k;
	// Then pop the top element in the heap;
	// Do this until the size of the heap is <= k;

	for(int i = 0; i < arr.size(); i++) {
		maxHeap.push(arr[i]);
		
		while(maxHeap.size() > k) {
			maxHeap.pop();
		}
	}

	return maxHeap.top();
}

int main() {
	vector<int>arr = {1, 2, 3, 4, 5, 100, 8};
	int k = 3;

	cout << kthSmallest(arr, k) << endl;
	cout << kthLargest(arr, k) << endl;
	return 0;

}