#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> arr) {
	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < arr[0].size(); j++) {
			arr[i][j] = arr[j][i];
		}
	}

	for(int i = 0; i < arr.size(); i++) {
		vector<int>row = arr[i];
		reverse(row.begin(), row.end());
	}

	return arr;
}

int main() {
	vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> res = solve(arr);

	for(auto array : res) {
		for(int x : array) cout << x << " ";
		cout << endl;
	}
	return 0;	
}
