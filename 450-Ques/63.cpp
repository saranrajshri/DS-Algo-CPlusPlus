#include<bits/stdc++.h>
using namespace std;


/*
	Approach - Dynamic Programming;
	Time - O(N ^ 2);
	Space - O(N), length of the wordDict;
*/ 

bool canBreak(string str, vector<string> wordDict) {
	unordered_set<string>s;
	for(string currentString : wordDict) s.insert(currentString);
	
	vector<bool>dp(str.size() + 1);	
	dp[0] = true;
	
	for(int i = 1; i < str.size() + 1; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(dp[j]) {
				string temp = str.substr(j, i - j);
				if(s.find(temp) != s.end()){
					dp[i] = true;
					break;
				}
			}
		}
	}

	return dp[str.size()];
}

int main() {
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	
	if(canBreak(s, wordDict)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}