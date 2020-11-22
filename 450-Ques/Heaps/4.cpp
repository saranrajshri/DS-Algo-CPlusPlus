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

int main() {
	vector<int>arr = {1, 2, 3, 4, 5};
	int k = 2;
	cout << solve(arr, k);
	return 0;	
}
