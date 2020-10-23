#include<bits/stdc++.h>
using namespace std;

/*
	Problem - Four Sum
	Time - O(N ^ 2) // Avg
	Space - O(n ^ 2) // Avg

	Time - O(N ^ 3) // worst
	Space - O(N ^ 3) // worst

*/	

vector<vector<int>> fourSum(vector<int> arr, int target) {
	unordered_map<int, vector<vector<int>>> m;
	vector<vector<int>> result;

	for(int i = 0; i < arr.size() - 1; i++) {
		for(int j = i + 1; j < arr.size(); j++) {
			int currentSum = arr[i] + arr[j];
			int difference = target - currentSum;

			// If a pair is already present 
			if(m.find(difference) != m.end()) {
				for(vector<int> pair : m[difference]) {
					pair.push_back(arr[i]);
					pair.push_back(arr[j]);
					result.push_back(pair);
				}
			}
		}


		for(int k = 0; k < i; k++) {
			int currentSum = arr[i] + arr[k];
			if(m.find(currentSum) == m.end()) {
				m[currentSum] = vector<vector<int>>{{arr[i], arr[k]}};
			}else{
				m[currentSum].push_back(vector<int>{arr[i], arr[k]});
			}
		}
	}

	return result;
}

int main() {
	vector<int>arr = {10, 2, 3, 4, 5, 7, 8};
	int target = 23;

	vector<vector<int>> res = fourSum(arr, target);

	for(auto arr : res) {
		for(int x : arr) cout << x << " ";
		cout << endl;
	}
	return 0;
}
