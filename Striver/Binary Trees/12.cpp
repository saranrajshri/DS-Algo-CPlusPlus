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

int height(TreeNode* root, bool &ans) {
	if(root == NULL) return 0;

	int left = height(root->left, ans);
	int right = height(root->right, ans);

	ans &= abs(left - right) < 2;

	return max(left, right) + 1;
}

bool solve(TreeNode* root) {
	bool ans = true;
	int h = height(root, ans);

	return ans;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	cout << solve(root) << endl ? "Yes" : "No";	
	return 0; 
} 
