#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>> arr) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	vector<int> res;

	for(auto l: arr) {
		for(int x : l) {
			minHeap.push(x);
		}
	}

	while(!minHeap.empty()) {
		res.push_back(minHeap.top());
		minHeap.pop();
	}

	return res;
}

int main() {
	vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> res = solve(arr);
	for(int x : res) cout << x << " ";
	return 0;	
}
