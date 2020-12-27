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


TreeNode* constructBinaryTree() {
	
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(2); 
	root->right	= new TreeNode(3); 
	root->left->left = new TreeNode(4); 
	root->left->right = new TreeNode(5); 

	return root;
}

TreeNode* flattenedRoot(TreeNode* root) {
	if(root == NULL) return NULL;
	TreeNode* tempRoot = root;

	while(root) {
		if(root->left) {
			TreeNode* leftTree = root->left;

			while(leftTree->right) {
				leftTree = leftTree->right;
			}

			leftTree->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}

		root = root->right;
	}

	return tempRoot;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	TreeNode* flattenedRoot = solve(root);	

	while(flattenedRoot) {
		cout << flattenedRoot->val << " ";
		flattenedRoot = flattenedRoot->right;
	} 
	
	return 0; 
} 