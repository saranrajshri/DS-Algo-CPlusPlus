#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode* children[26];
	int isLeaf;
};

TrieNode* getNode(void) {
	TrieNode* newTrieNode = new TrieNode;
	newTrieNode->isLeaf = -1;

	for(int i = 0; i < 26; i++) {
		newTrieNode->children[i] = NULL;
	}

	return newTrieNode;
}

int getTagIndex(TrieNode* root, string word, int &anagramIndex) {
	TrieNode* pCrawl = root;

	for(int i = 0; i < word.size(); i++) {
		int index= word[i] - 'a';
		if(pCrawl->children[index] == NULL) {
			pCrawl->children[index] = getNode();
		}

		pCrawl = pCrawl->children[index]; 
	}

	if(pCrawl->isLeaf == -1) pCrawl->isLeaf = ++anagramIndex;

	return pCrawl->isLeaf;
}

vector<vector<string>> groupAnagrams(vector<string> words) {

	vector<vector<string>> anagramGroups;

	TrieNode* root = getNode();
	
	int anagramIndex = -1;


	for(int i = 0; i < words.size(); i++) {
		string tag = words[i];

		sort(tag.begin(), tag.end());

		int tagIndex = getTagIndex(root, tag, anagramIndex);	

		if(tagIndex == anagramGroups.size()) {
			anagramGroups.push_back(vector<string>(1, words[i]));
		}else{
			anagramGroups[tagIndex].push_back(words[i]);
		}
	}

	return anagramGroups;
}

int main() {
	vector<string> words = {"act","god","cat","dog","tac"};
	vector<vector<string>> res = groupAnagrams(words);

	for(auto arr : res) {
		for(string res : arr) {
			cout << res << " ";
		}
		cout << endl;
	}
	return 0;	
}
