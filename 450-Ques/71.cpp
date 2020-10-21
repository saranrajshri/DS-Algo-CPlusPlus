#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Bucket Sort

*/	
	
vector<string> topKFrequentWords(vector<string>words, int k) {
	unordered_map<string, int>m;
	vector<string>res;
	for(string s : words) m[s]++;

	vector<vector<string>> bucket(words.size() + 1, vector<string>());

	for(auto it : m) {
		bucket[it.second].push_back(it.first);
	}

	int count = 0;
	for(int i = bucket.size() - 1; i >= 0; i--) {
		for(int j = 0; j < bucket[i].size(); j++) {
			if(count == k) return res;
			count++;
			res.push_back(bucket[i][j]);
		}
	}

	return res;
}

int main() {
	vector<string> words = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
	int k = 2;
	vector<string> res = topKFrequentWords(words, k);
	
	for(string s : res) cout << s << endl;
	return 0;
}