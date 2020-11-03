#include <bits/stdc++.h> 
using namespace std; 

/*
	Binary Tree
	Template from geek for geeks
*/		

struct TreeNode { 
	int val; 
	struct TreeNode* left, *right; 

	TreeNode(int data) { 
		this->val = data; 
		left = right = NULL; 
	} 
}; 

/*
	Time - O(N);
	Space - O(N);
*/		

TreeNode* helper(vector<int>preOrder, vector<int>inOrder, int left, int right, int &index, unordered_map<int, int>m) {
	if(left > right) return NULL;
	int nextIndex = m[preOrder[index++]];

	TreeNode* newNode = new TreeNode(preOrder[index]);
	newNode->left = helper(preOrder, inOrder, left, nextIndex - 1, index, m);
	newNode->right = helper(preOrder, inOrder, nextIndex + 1, right, index, m);

	return newNode;
}

TreeNode* buildTree(vector<int>preOrder, vector<int>inOrder) {
	int index = 0;
	unordered_map<int, int>m;

	for(int i = 0; i < inOrder.size(); i++) {
		m[inOrder[i]] = i;
	}

	return helper(preOrder, inOrder, 0, preOrder.size() - 1, index, m);
}

void inorder(TreeNode* root) {
	if(root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

int main() { 
	vector<int>preOrder = {3,9,20,15,7};
	vector<int>inOrder = {9,3,15,20,7};
	TreeNode* root =  buildTree(preOrder, inOrder);		
	inorder(root);
	return 0; 
} 