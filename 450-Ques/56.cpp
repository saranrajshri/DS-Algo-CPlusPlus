#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1 - DFS + Backtracking
*/ 

void generateSequenceHelper(string s, int index, string currentString, vector<string> &res) {
	if(index >= s.size()) return;

	if(currentString.size() != 0) res.push_back(currentString);

	for(int i = index; i < s.size(); i++) {
		string currentString = currentString + s[i];
		generateSequenceHelper(s, i + 1, currentString, res);
		currentString.pop_back();
	}
}

/*
	Approach 2 - Pick or dont pick
*/ 
void  generateSequenceHelper(string s, string currentString, vector<string>&res) {
	if(s.size() == 0) {
		res.push_back(currentString);
		return;
	}

	generateSequenceHelper(s.substr(1), currentString + s[0], res);
	generateSequenceHelper(s.substr(1), currentString, res);


}

vector<string> generateAllSequences(string s) {
	vector<string> res;

	generateSequenceHelper(s, "", res);

	return res;
}

int main() {
	string s = "abc";
	vector<string>res = generateAllSequences(s);

	// for(string str : res) cout << str << endl;
	return 0;
}
