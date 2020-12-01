#include<bits/stdc++.h>
using namespace std;

int solve(string beginWord, string endWord, vector<string> wordsList) {
	unordered_set<string> dict(wordsList.begin(), wordsList.end());
	int res = 0;
	queue<string>q;

	q.push(beginWord);

	while(!q.empty()) {
		res++;
		int n = q.size();
		for(int i = 0; i < n; i++) {
			string currentString = q.front();
			q.pop();

			if(currentString == endWord) return res;

			for(int j = 0; j < currentString.size(); j++) {
				char tempChar = currentString[j];

				for(char c = 'a'; c <= 'z'; c++) {
					currentString[j] = c;
					if(dict.find(currentString) != dict.end()) {
						dict.erase(currentString);
						q.push(currentString);
					}
				}

				currentString[j] = tempChar;
			}			
		}

	}

	return res;
}

int main() {
	vector<string> wordsList = {"hot","dot","dog","lot","log","cog"};
	string beginWord = "hit";
	string endWord = "cog";

	cout << solve(beginWord, endWord, wordsList);
	return 0;	
}
