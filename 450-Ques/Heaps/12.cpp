#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int x : arr) minHeap.push(x);

	int sum = 0;

	while(minHeap.size() > 1) {
		int element1 = minHeap.top();
		minHeap.pop();
		int element2 = minHeap.top();
		minHeap.pop();

		sum += element1 + element2;
		minHeap.push(element1 + element2);
	}

	return sum;
}

int main() {
	vector<int>arr = { 4, 3, 2, 6};
	cout << solve(arr) << endl;
	return 0;	
}
