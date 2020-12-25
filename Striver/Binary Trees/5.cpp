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

int helper(TreeNode* root) {
	if(root == NULL) return 0;

	int left = helper(root->left);
	int right = helper(root->right);

	return (max(left, right) + 1);	
}


int main() { 
	TreeNode* root = constructBinaryTree();
	cout << helper(root);	
	return 0; 
} 