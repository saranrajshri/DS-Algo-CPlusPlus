#include<bits/stdc++.h>
using namespace std;

/*
	Approach - DFS
	Time - O(N ^ 2);
	Space - O(N);
*/ 

void formSentencesHelper(vector<vector<string>>words, int row, int col, vector<string>currentSentence, vector<vector<string>>&res){
	currentSentence.push_back(words[row][col]);
	if(row == words.size() - 1) {
		res.push_back(currentSentence);
		return;
	}
	
	if(row + 1 < words.size()) {
		for(int i = 0; i < words[row + 1].size(); i++) {
			if (words[row + 1][i] != "")
				formSentencesHelper(words, row + 1, i, currentSentence, res);
		}
	}	
}

vector<vector<string>> formSentences(vector<vector<string>> words) {
	vector<vector<string>>res;
	vector<string>currentSentence;

	for(int col = 0; col < words[0].size(); col++) {
		formSentencesHelper(words, 0, col, currentSentence, res);
	}

	return res;
}

int main() {
	vector<vector<string>> words = {{"you", "we"},
			                        {"have", "are"},
			                        {"sleep", "eat", "drink"}};

    vector<vector<string>> res = formSentences(words);
	
    for(auto str : res) {
    	for(auto x : str) {
    		cout << x << " ";
    	} 
    	cout << endl;
    }
	return 0;
}