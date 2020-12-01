#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n) {
	vector<vector<int>> res;

	for(int i = 0; i < n; i++) {
		res.push_back(vector<int>(i + 1, 1));

		for(int j = 1; j < i; j++) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	return res;
}

int main() {
	int n = 5;
	vector<vector<int>> res = solve(n);

	for(auto arr : res) {
		for(int x : arr) cout << x << " ";
		cout << endl;
	} 
	return 0;	
}
