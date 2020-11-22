#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int x : arr) {
		minHeap.push(x);
		while(minHeap.size() > k) minHeap.pop();
	}

	return minHeap.top();
}

int solve1(vector<int> arr, int k) {
	priority_queue<int, vector<int>> maxHeap;

	for(int x : arr) {
		maxHeap.push(x);
		while(maxHeap.size() > k) maxHeap.pop();
	}

	return maxHeap.top();
}

int main() {
	vector<int>arr = {1, 2, 3, 4, 5};
	int k = 2;
	cout << solve(arr, k) << endl;
	cout << solve1(arr, k) << endl;
	return 0;	
}
