#include<bits/stdc++.h>
using namespace std;


struct TrieNode {
	struct TrieNode* children[26];
	int freq;
};


TrieNode* getNode(void) {
	TrieNode* newTrieNode = new TrieNode;
	newTrieNode->freq = 0;

	for(int i = 0; i < 26; i++) {
		newTrieNode->children[i] = NULL;
	}

	return newTrieNode;
}

void insert(TrieNode* root, string word) {
	TriNode* pCrawl = root;

	for(int i = 0; i < word.size(); i++) {
		int index = word[i] - 'a';
		if(pCrawl->children[index] == NULL) {
			pCrawl->children[index] = getNode();
		}else{
			pCrawl->children[index]->freq++;
		}

		pCrawl = pCrawl->children[index];
	}	
}


void helper(TrieNode* root, vector<string> &res) {
	if(root == NULL) return;

	if(root->freq == 1) { 
		res.push_back("/0");
		return;
	}

	for(int i = 0; i < 26; i++) {
		if(root->children[i] != NULL) {
			res[index] = i;
			helper(root->children[i], res);
		}
	}
}

void solve(vector<string> words, vector<string> &res) {
	TrieNode* root = getNode();

	for(string s : words) {
		insert(root, s);
	}

	helper(root, res);
}

int main() {
	vector<string> words = {"zebra", "dove", "duck", "dog"};
	vector<string> res;
	
	solve(words, res);

	return 0;
}
