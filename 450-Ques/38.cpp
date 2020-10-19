#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Binary Search
	1. Don't treat it as a matrix, treat it as sorted list,
	2. Apply the binary search algorithm;
	3. Tricky part is finding the mid element;

	Time - O(log N);
	Space - O(1);
*/ 

bool search2DMatrix(vector<vector<int>> matrix, int target) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	int start = 0;
	int end = rows * cols - 1;

	while(start <= end) {
		int mid = (start + end) / 2;
		int currentElement = matrix[mid / cols][mid % cols];

		if(currentElement == target) return true;
		else if(currentElement < target) start = mid + 1;
		else end = mid - 1;
	}

	return false;
}

bool search2DMatrix(vector<vector<int>> matrix, int target) {
	int row = 0;
	int col = matrix[0].size();

	while(row < matrix.size() && col >= 0) {
		if(matrix[row][col] == target) return true;
		else if(matrix[row][col] > target) col--;
		else{
			row--;
		}
	}

	return false;
}

int main() {
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	int target = 300;
	if(search2DMatrix(matrix, target)){
		cout << "Yes" << endl; 
	}else{
		cout << "No" << endl;
	}
	return 0;
}