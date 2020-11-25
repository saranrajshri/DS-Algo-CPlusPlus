#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TrieNode* getNode(void) {
	TrieNode* newTrieNode = new TrieNode;
	newTrieNode->isEndOfWord = false;

	for(int i = 0; i < 26; i++) {
		newTrieNode->children[i] = NULL;
	}

	return newTrieNode;
}

void insert(TrieNode* root, string word) {
	TrieNode* pCrawl = root;

	for(int i = 0; i < word.size(); i++) {
		int index = word[i] - 'a';
		if(pCrawl->children[index] == NULL) {
			pCrawl->children[index] = getNode();
		}

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string word) {
	TrieNode* pCrawl = root;

	for(int i = 0; i < word.size(); i++) {
		int index = word[i] - 'a';

		if(pCrawl->children[index] == NULL) return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl && pCrawl->isEndOfWord);
}

int main() {
	TrieNode* root = getNode();
	insert(root, "the");
	insert(root, "there");
	insert(root, "theapple");

	cout << search(root, "there") << endl;
	cout << search(root, "thee") << endl;

	return 0;	
}
