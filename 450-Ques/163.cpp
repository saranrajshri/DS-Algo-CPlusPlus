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

/*
	Time - O(N);
	Space - O(N);
*/		

void leftView(TreeNode* root, int &maxLevel, int level, vector<int>&res) {
	if(root) {
		if(maxLevel < level) {
			res.push_back(root->val);
			maxLevel = level;
		}

		leftView(root->left, maxLevel, level + 1, res);
		leftView(root->right, maxLevel, level + 1, res);
	}
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>res;
	int maxLevel = 0;
	leftView(root, maxLevel, 1, res);	
	for(int x : res)  cout << x << " ";
	return 0; 
} 