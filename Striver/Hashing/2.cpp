#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(N ^ 2);
	Space - O(N);
*/

vector<vector<int>> solve(vector<int>arr, int target) {
	vector<vector<int>>res;
	multimap<int, pair<int, int>> m;
	set<vector<int>>s;

	for(int i = 0; i < arr.size(); i++) {
		for(int j = i + 1; j < arr.size(); j++) {
			int targetToFind = target - (arr[i] + arr[j]);

			auto it = m.equal_range(targetToFind);

			for(auto rangeIterator = it.first; rangeIterator != it.second; rangeIterator++) {
				int indexOne = rangeIterator->second.first;
				int indexTwo = rangeIterator->second.second;

				if(i != indexOne && j != indexOne && i != indexTwo && j != indexOne) {
					vector<int>currentAns = {arr[indexOne], arr[indexTwo], arr[i], arr[j]};
					sort(currentAns.begin(), currentAns.end());

					if(s.find(currentAns) == s.end()) {
						s.insert(currentAns);
						res.push_back(currentAns);
					}
				}
			}

			m.emplace(arr[i] + arr[j], make_pair(i, j));
		}
	}

	return res;
}

int main() {
	vector<int>arr = {1,0,-1,0,-2,2};
	int target = 0;
	vector<vector<int>> res = solve(arr, target);

	for(auto array : res) {
		for(int x : array) cout << x << " ";
		cout << endl;
	}
	return 0;	
}
