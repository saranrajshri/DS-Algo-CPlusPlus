#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode* children[26];
	bool isLeaf;
};

TrieNode* getNode(void) {
	TrieNode* newTrieNode = new TrieNode;
	newTrieNode->isLeaf = false;

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

	pCrawl->isLeaf = true;
}

void helper(TrieNode* root, string prefix) {
	if(root->isLeaf) {
		cout << prefix << endl;
	}

	for(int i = 0; i < 26; i++){
		if(root->children[i] != NULL) {
 			helper(root->children[i], prefix + (char)i);
		}
	}
}

void solve(vector<string> words) {
	TrieNode* root = getNode();

	insert(root, words[0]);
	insert(root, words[1]);
	
	string word = "gekk";
	
	string prefix = "";
	TrieNode* prevNode = root;
	

	for(int i = 0; i < word.size(); i++) {
		char lastChar = word[i];
		TrieNode* currentNode = prevNode->children[lastChar - 'a'];	
		
		prefix += word[i];

		if(currentNode == NULL) {
			cout << "No Suggestions for " << prefix << endl;
			i++;
			break;
		}

		cout << "Suggestions for " << prefix << endl;
		helper(currentNode, prefix);

		prevNode = currentNode;
	}
}

int main() {
	vector<string> words = {"gforgeeks", "geeksquiz"};
	solve(words);
	return 0;
}
