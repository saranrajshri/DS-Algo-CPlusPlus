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

bool wordBreak(TrieNode* root, string word) {
	if(word.size() == 0) return true;

	for(int i = 1; i <= word.size(); i++) {
		if(search(root, word.substr(0,  i)) && wordBreak(root, word.substr(i, word.size() - i))) return true;
	}

	return false;
}


int main() {
	vector<string> words = {"mobile","samsung","sam", 
                           "sung","ma\n","mango", 
                           "icecream","and","go","i", 
                           "like","ice","cream"}; 

    TrieNode* root = getNode(); 
    
    for(string x : words) {
    	insert(root, x);
    }

    cout << wordBreak(root, "ilikesamsung") << endl;
    cout << wordBreak(root, "samsungandmangok") << endl;

	return 0;	
}
