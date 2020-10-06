#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>pascalsTriangle(int numRows){
	vector<vector<int>>res;

	for(int i = 0; i < numRows; i++) {
		res.push_back(vector<int>(i + 1, 1));

		for(int j = 1; j < i; j++) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	return res;
}

int main() {
	int numRows = 3;
	vector<vector<int>> result = pascalsTriangle(numRows);
	

	for(auto vec1 : result) {
		for(auto vec2 : vec1) {
			cout << vec2 <<  " ";
		}
		cout << endl;
	}
	return 0;
}