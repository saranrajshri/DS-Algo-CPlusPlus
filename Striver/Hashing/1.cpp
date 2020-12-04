#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve(vector<int> arr, int target) {
	unordered_map<int, int> m;
	vector<pair<int, int>> res;

	for(int i = 0;  i < arr.size(); i++) {
		int targetToFind = target - arr[i];

		auto it = m.find(targetToFind);
		if(it != m.end()) {
			res.push_back(make_pair(arr[i], it->first));
		}else{
			m[arr[i]] = i;
		}
	}

	return res;
}

int main() {
	vector<int>arr  = {1, 2, 3, 4, 5};
	int target = 8;
	vector<pair<int, int>> res = solve(arr, target);

	for(pair<int, int> x : res) {
		cout << x.first << " " << x.second;
	}
	return 0;	
}
