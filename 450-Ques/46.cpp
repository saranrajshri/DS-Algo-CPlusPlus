#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Use HashMap;
	Time - O(M * N);
	Space - O(N) // where N is the number of elements in the first row of the matrix;
*/ 

vector<int> commonElementsInRows(vector<vector<int>> matrix) {
	vector<int>res;
	unordered_map<int, int>m;

	// Initilize the first row values to 1;
	for(int i = 0; i < matrix[0].size(); i++) {
		m[matrix[0][i]] = 1;
	}

	for(int i = 1; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			
			// If the element is present in the hashmap, then increment the value.
			if(m[matrix[i][j]] == i){
				m[matrix[i][j]]++;

				// If we are at the last row, then push the values to the res. 
				if(i == matrix.size() - 1) {
					res.push_back(matrix[i][j]);
				}
			}
 		}
	}

	return res;
}

int main() {
	vector<vector<int>> matrix = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

    vector<int> res = commonElementsInRows(matrix);

    for(int x : res) cout << x << " ";
	return 0;
}