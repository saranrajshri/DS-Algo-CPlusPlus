#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sort + Hashmap
	Time - O(n log n) // Sorting
	Space - O(N)	;
*/ 

void groupAnagrams(vector<string> words) {
	unordered_map<string, vector<string>> m;

	for(string s : words){
		string temp = s;
		sort(s.begin(), s.end());

		if(m.find(s) == m.end()) {
			m[s] = vector<string>{temp};
		}else{
			m[s].push_back(temp);
		}
	}

	for(auto it : m) {
		for(string str : it.second) {
			cout << str << " ";
		}
		cout << endl;
	}

}	

int main() {
	vector<string> words = {"act", "cat", "tac", "god", "dog"};
	groupAnagrams(words);
	return 0;
}
