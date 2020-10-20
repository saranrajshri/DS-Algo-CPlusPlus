#include<bits/stdc++.h>
using namespace std;

/*

	Approach - HashMap

	Time - O(N);
	Space - O(N);
	
*/ 

vector<char> findDuplicates(string s) {
	vector<char>res;
	unordered_map<int, int>m;

	for(char c : s) m[c]++;

	for(auto it : m){
		if(it.second > 1) res.push_back(it.first);
	}

	return res;
}

int main() {
	string s = "Hello World";

	vector<char> res = findDuplicates(s);
	for(char c : res) cout << c << " ";

	return 0;
}