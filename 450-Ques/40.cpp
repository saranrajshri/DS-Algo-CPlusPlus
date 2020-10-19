#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Min Heap;
	1. Insert all the elements in the minheap and pop it from the heap.
	2. Push it to the resultant array;	
*/ 
vector<int> sortedMatrix(vector<vector<int>> matrix) {
	priority_queue<int, vector<int>, greater<int>>maxHeap;
	
	int m = matrix.size();
	int n = matrix[0].size();
	int index = 0;
	vector<int>res(m * n);
	
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			maxHeap.push(matrix[i][j]);
		}
	}

	while(!maxHeap.empty()) {
		int top = maxHeap.top();
		maxHeap.pop();
		res[index++] = top;
	}

	return res;
}

int main() {
	vector<vector<int>>matrix = { {10, 20, 30, 40}, 
                    	{15, 25, 35, 45}, 
                   	 	{27, 29, 37, 48}, 
                    	{32, 33, 39, 50}, 
               			};	

    vector<int>res = sortedMatrix(matrix);
	for(int x : res) {
		cout << x << " "; 
	}
	return 0;
}