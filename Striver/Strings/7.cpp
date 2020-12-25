#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(vector<string> arr) {
	vector<vector<string>> res;
	unordered_map<string, vector<string>> m;

	for(int i = 0; i < arr.size(); i++) {
		string current = arr[i];
		sort(current.begin(), current.end());
		
		if(m.find(current) == m.end()) {
			m[current] = vector<string>{arr[i]};
		}else{
			m[current].push_back(arr[i]);
		}
	}

	for(auto it : m) {
		res.push_back(it.second);
	}

	return res;
}

int main() {
	vector<string> arr = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> res = solve(arr);

	for(auto arr : res) {
		for(string s : arr) cout << s << " ";
		cout << endl; 
	}
	return 0;	
}
