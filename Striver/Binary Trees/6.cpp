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

int height(TreeNode* root, int &diameter) {
	if(root == NULL) return 0;

	int left = height(root->left, diameter);
	int right = height(root->right, diameter);

	diameter = max(diameter, (left + right + 1));

	return (max(left, right) + 1);
}

int solve(TreeNode* root) {
	int diameter = INT_MIN;
	int ans = height(root, diameter);

	return diameter;
}


int main() { 
	TreeNode* root = constructBinaryTree();
	cout << solve(root);	
	return 0; 
} 