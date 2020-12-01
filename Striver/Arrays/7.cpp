#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> matrix) {
	vector<int> row(matrix.size(), -1);
	vector<int> col(matrix[0].size(), -1);

	for(int i = 0; i < matrix.size(); i++) {
 		for(int j = 0; j < matrix[0].size(); j++) {
			if(matrix[i][j] == 0){
				row[i] = 0;
				col[j] = 0;
			}
 		}
 	}

 	for(int i = 0; i < matrix.size(); i++) {
 		for(int j = 0; j < matrix[0].size(); j++) {
 			if(row[i] == 0 || col[j] == 0) {
 				matrix[i][j] = 0;
 			}
 		}
 	}

 	return matrix;
}

/*
	Constant Space Approach
*/

vector<vector<int>> solve(vector<vector<int>> matrix) {
	bool isZeroRow = false;
	bool isZeroCol = false;

	for(int i = 0; i < matrix[0].size(); i++) {
		if(matrix[0][i] == 0) {
			isZeroRow = true;
			break;
		}
	}

	for(int j = 0; j < matrix.size(); j++) {
		if(matrix[j][0] == 0) {
			isZeroCol = true;
			break;
		}
	}

	for(int i = 1; i < matrix.size(); i++) {
		for(int j = 1; j < matrix[0].size(); j++) {
			if(matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for(int i = 1; i < matrix.size(); i++) {
		for(int j = 1; j < matrix[0].size(); j++) {
			if(matrix[0][j] == 0 || matrix[i][0] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if(isZeroRow) {
		for(int i = 0; i < matrix[0].size(); i++) {
			matrix[0][i] = 0;
		}
	}

	if(isZeroCol) {
		for(int j = 0; j < matrix.size(); j++) {
			matrix[j][0] = 0;
		}
	}

	return matrix;
}



int main() {
	vector<vector<int>> matrix = {{1, 1, 1},
								   {1, 0, 1},
								   {1, 1, 1}};
    vector<vector<int>> res = solve(matrix);

    for(auto arr : res) {
    	for(int x : arr) cout << x << " ";
    	cout << endl;
    }
	return 0;	
}

