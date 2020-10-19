#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(N) where N is the number of elements in the matrix
	Space - O(1);

*/ 

vector<int>spiralTraverse(vector<vector<int>>matrix) {
	int m = matrix.size(), n = matrix[0].size(), up = 0, left = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
	vector<int>res(m * n);
	int index = 0;
	while(up <= down && left <= right) {
		for(int col = left; col <= right; col++) {
			res[index++] = matrix[up][col];
		}

		if(++up > down) break;

		for(int row = up; row <= down;  row++) {
			res[index++] = matrix[row][right];
		}

		if(--right < left) break;

		for(int col = right; col >= left; col--) {
			res[index++] = matrix[down][col];
		}

		if(--down < up) break;

		for(int row = down; row >= up; row--) {
			res[index++] = matrix[row][left];
		}

		if(left++ > right) break;

		for(int col = left; col < right; col++) {
			res[index++] = matrix[up][col];
		}
	}

	return res;
	
}

int main() {
	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 8, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	vector<int>res = spiralTraverse(matrix);

	for(int x : res) {
		cout << x << " ";
	}
	return 0;
}