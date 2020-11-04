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
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(2); 
    root->right->left->left = new TreeNode(4); 
    
	return root;
}

string helper(TreeNode* root, unordered_map<string, int>&m) {
	if(root == NULL) return "";

	string currentPath = "(";
	currentPath += helper(root->left, m);
	currentPath += to_string(root->val);
	currentPath += helper(root->right, m);
	currentPath += ")";
	
	if(m[currentPath] >= 1) {
		cout << currentPath <<  endl;
	}
	m[currentPath]++;

	return currentPath;
}

void findDuplicateSubTrees(TreeNode* root) {
	unordered_map<string, int>m;
	helper(root, m);
}

int main() { 
	TreeNode* root = constructBinaryTree();
	findDuplicateSubTrees(root);
	return 0; 
} 