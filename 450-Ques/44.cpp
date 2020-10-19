#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1;

	Transpose the matrix and reverse each row;
	 
	Time - O(N ^ 2);
	Space - O(1);
*/ 

void rotate90Deg(vector<vector<int>>&matrix) {
	if(matrix.empty()) return;

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = matrix[j][i];
		}
	}

	for(int i = 0; i < matrix.size(); i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}
	
int main() {
	vector<vector<int>>matrix = { { 1, 2, 3, 4 }, 
			                      { 5, 6, 7, 8 }, 
			                      { 9, 10, 11, 12 }, 
			                      { 13, 14, 15, 16 } }; 
	rotate90Deg(matrix);

	for(auto array : matrix) {
		for(int x : array) cout << x << " "; 
		cout << endl;
	}
	return 0;
}