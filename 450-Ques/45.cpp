#include<bits/stdc++.h>
using namespace std;

/*
	Simple Approach is to use Heaps
	use MaxHeap
	Time - O(N), number of elements in the matrix;
	Space - O(K),
*/ 


/*
	Approach - Binary Search (Optimal)
	Very Tricky Problem

	Time - O(n * log(n) * log(N));
	Space - O(1);
*/ 

int kthSmallest(vector<vector<int>>matrix, int k) {
	 int n = matrix.size();

	 int left = matrix[0][0];
	 int right = matrix[n - 1][n - 1];

	 while(left < right) {
	 	int midValue = left + (right - left) / 2;

	 	int count = 0;
	 	for(int i = 0; i < n; i++) {
	 		vector<int>row = matrix[i];
	 		count += upper_bound(row.begin(), row.end(), midValue) - row.begin();
	 	}

	 	if(count < k) left = midValue + 1;
	 	else right = midValue;
	 }

	 return left;
}

int main() {
	vector<vector<int>> matrix = {
								   { 1,  5,  9},
								   {10, 11, 13},
								   {12, 13, 15}
								};
	int k = 8;
	cout << kthSmallest(matrix, k);
	return 0;
}