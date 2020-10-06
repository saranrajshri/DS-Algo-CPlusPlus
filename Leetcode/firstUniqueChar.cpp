#include<bits/stdc++.h>
using namespace std;

// Traverse Two times
int firstUniqueChar(string s) {
	unordered_map<char, int>m;
	for(char c : s){
		m[c]++;
	}

	for(int i = 0; i < s.size(); i++) {
		if(m[s[i]] == 1) return i;
	}

	return -1;
}

// Single Traverse solution
int firstUniqueChar(string s) {
	unordered_map<char, pair<int, int>>m;
	int minIndex = INT_MAX;

	for(int i = 0; i < s.size(); i++) {
		m[s[i]].first++;
		m[s[i]].second = i;
	} 

	for(auto it : m){
		if(it.second.first == 1) {
			minIndex = min(minIndex, it.second.second);
		}
	}

	return minIndex == INT_MAX ? -1 : minIndex;
}

int main() {
	string s = "leetcode";
	cout << firstUniqueChar(s);
	return 0;
}