#include<bits/stdc++.h>
using namespace std;


void subSetHelper(vector<int> arr, int index, vector<int> currentSubSet, vector<vector<int>>& result) {
	
	result.push_back(currentSubSet);
	

	for(int i = index; i < arr.size(); i++) {
		currentSubSet.push_back(arr[i]);
		subSetHelper(arr, i + 1, currentSubSet, result);
		currentSubSet.pop_back();
	}
}

void solve(vector<int> arr, vector<vector<int>> &result) {
	subSetHelper(arr, 0, {}, result);
}


int main() {
	vector<int> arr = {1, 2, 3, 4};
	
	vector<vector<int>> result;
	solve(arr, result);

	for(auto a : result) {
		for(auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}