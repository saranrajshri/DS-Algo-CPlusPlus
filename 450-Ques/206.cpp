#include<bits/stdc++.h>
using namespace std;


void wordBreakHelper(string s, int n, string result, vector<string>&res, unordered_set<string>wordsDict) {

	for(int i = 1; i <= n; i++) {
		string prefix = s.substr(0, i);

		if(wordsDict.find(prefix) != wordsDict.end()){
			if(i == n) {
				result += prefix;
				res.push_back(result);
				return;
			}
		}

		wordBreakHelper(s.substr(i, n - i), n - i, result + prefix + " ", res, wordsDict);
	}
}

vector<string> wordBreak(string s, vector<string> dict) {
	unordered_set<string>wordsDict;

	for(string x : dict) wordsDict.insert(x);

	vector<string> res;
	wordBreakHelper(s, s.size(), "", res, wordsDict);
	
	return res;
}

int main() {
	vector<string> dict = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
	vector<string> res = wordBreak("iloveicecreamandmango", dict);                        
	for(string x : res) {
		cout << x << endl;
	}
	return 0;
}