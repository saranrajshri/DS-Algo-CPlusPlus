#include<bits/stdc++.h>
using namespace std;


/*
	Approach 1 - Simple Traverse
	Time - O(M * N);
	Space - O(1);
*/ 

int rowWithMaxOnes(vector<vector<int>>matrix) {
	int maxRowIndex = -1;
	int maxCount = INT_MIN;

	for(int i = 0; i < matrix.size(); i++) {
		int onesCount = 0;
		for(int j = 0; j < matrix[i].size(); j++) {
			if(matrix[i][j] == 1) onesCount++;
		}	

		if(onesCount > maxCount) {
			maxCount = onesCount;
			maxRowIndex = i;
		}
	}

	return maxRowIndex;
}

/*
	Approach 2 - Traverse + Binary Search
	Since each row is sorted, we can use binary search;


	Time - O(M * log N);
	Space - O(1);
*/ 

int lowerBound(vector<int>arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		int mid = left + (right - left) / 2;

		if(arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}

	return left;
}

int rowWithMaxOnes(vector<vector<int>> matrix) {
	int maxRowIndex = -1;
	int maxCount = INT_MIN;

	for(int i = 0; i < matrix.size(); i++) {
		vector<int>currentRow = matrix[i];
		int leftIndex = lowerBound(currentRow, 1);
		int rightIndex = lowerBound(currentRow, 2) - 1;

		int onesCount = rightIndex - leftIndex;
		if(onesCount > maxCount) {
			maxCount = onesCount;
			maxRowIndex = i;
		}
	}

	return maxRowIndex;
}

int main() {
	vector<vector<int>> matrix = { {0, 0, 0, 1},  
                    {0, 1, 1, 1},  
                    {1, 1, 1, 1},  
                    {0, 0, 0, 0}};
	cout << rowWithMaxOnes(matrix);  
	return 0;
}