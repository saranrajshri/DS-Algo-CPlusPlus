#include<bits/stdc++.h>
using namespace std;

/*
	Approch - Using HashMap
	Time - O(N);
	Space - O(N);
*/ 



vector<pair<int, int>> subArraysWithZero(vector<int> nums) {
	vector<pair<int, int>> res;
	unordered_map<int, vector<int>> m;
	int sum = 0;

	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i];

		if(sum == 0) {
			res.push_back(make_pair(0, i));
		}

		auto it = m.find(sum);
		if(it != m.end()) {
			vector<int> arr = it->second;
			for(int j = 0; j < arr.size(); j++) {
				res.push_back(make_pair(arr[j] + 1, i));
			}
		}

		m[sum].push_back(i);	
	}

	return res;
}

int main() {
	vector<int> arr =  {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
	vector<pair<int, int>> res = subArraysWithZero(arr);


	for(pair<int, int> currentPair : res) {
		cout << currentPair.first << " " << currentPair.second << endl;
	}
	return 0;
}
