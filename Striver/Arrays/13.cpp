#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();

	if(matrix.empty()) return false;
	int row = 0;
	int col = n - 1;

	while(row < matrix.size() && col >= 0) {
		if(matrix[row][col] == target) return true;
		else if(matrix[row][col] > target) col--;
		else row++;
	}	

	return false;	
}

int main() {
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	if(search(matrix, 3)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;	
}
