#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> pair1, vector<int> pair2) {
	return pair1[1] < pair2[1];
}

vector<vector<int>> solve(vector<vector<int>> arr) {
	vector<vector<int>> res;

	sort(arr.begin(), arr.end(), comparator);

	res.push_back(arr[0]);

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i][0] > res.back()[1]) res.push_back(arr[i]);
		else{
			res.back()[1] = max(res.back()[1], arr[i][1]);
		}
	}

	return res;
}

int main() {
	vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> res = solve(arr);

	for(auto array : res) {
		for(int x : array) cout << x << " ";
		cout << endl;
	}
	return 0;	
}
