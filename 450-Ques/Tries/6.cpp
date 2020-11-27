#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> matrix) {
	vector<vector<int>> res;
	set<vector<int>> s;

	for(vector<int> arr : matrix) {
		s.insert(arr);
	}

	for(auto it : s) {
		res.push_back(it);
	}
	return res;
}

int main() {
	vector<vector<int>> matrix = {{1, 1, 0, 1},{1, 0, 0, 1},{1, 1, 0, 1}};
	vector<vector<int>> res = solve(matrix);
	
	for(vector<int>arr : res) {
		for(int x : arr) cout << x << " ";
		cout << endl;
	}
	return 0;
}

	
