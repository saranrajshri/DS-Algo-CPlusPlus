#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Simple
	Convert the matrix into an array and sort it.
	Find the middle value;

	Time  - O(N Log N), N - Number of elements in the matrix
	Space - O(N), Number of elements in matrix;
*/ 

/*
	Approach - Using Binary Search
	Time - O(row * log (col));
	Space - O(1);
*/ 

// Similar Problem Kth Smallest in Sorted Matrix 

int medianOfMatrix(vector<vector<int>> matrix) {
	int left = INT_MAX;
	int right = INT_MIN;

	for(int row = 0; row < matrix.size(); row++) {
		left = min(left, matrix[row][0]);
		right = max(right, matrix[row][matrix.size() -1 ]);
	}	

	int k = (matrix.size() * matrix[0].size() + 1) / 2;
	while(left < right) {
		int midValue = left + (right - left) / 2;

		int count = 0;

		for(int i = 0; i < matrix.size(); i++) {
			vector<int>row = matrix[i];
			count += upper_bound(row.begin(), row.end(), midValue) - row.begin();
		} 

		if(count < k) left = midValue + 1;
		else right = midValue;
	}

	return left;
}

int main() {
	vector<vector<int>>matrix = { {1,3,5}, {2,6,9}, {3,6,9} };
	cout << medianOfMatrix(matrix);
	return 0;
}