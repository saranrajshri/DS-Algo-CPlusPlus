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

void helper(TreeNode* root, int currentLevel, int &maxLevel, vector<int>&res) {
	if(root == NULL) return;

	if(maxLevel < currentLevel) {
		res.push_back(root->val);
		maxLevel = currentLevel;
	}


	helper(root->left, currentLevel + 1, maxLevel, res);
	helper(root->right, currentLevel + 1, maxLevel, res);
}

vector<int> solve(TreeNode* root) {
	vector<int> res;
	int maxLevel = -1;
	helper(root, 0, maxLevel, res);

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();

	vector<int> res = solve(root);	
	for(int x : res) cout << x << " ";
	return 0; 
} 