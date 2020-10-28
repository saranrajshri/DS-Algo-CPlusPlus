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
	Tree Traversal

	Approach - Recursion
	Time - O(N);
	Space - O(N);
*/		

void inorder(TreeNode* root, vector<int>&inorderRes) {
	if(root) {
		inorder(root->left, inorderRes);
		inorderRes.push_back(root->val);
		inorder(root->right, inorderRes);
	}
}

/*
	Approach - Iterative
	Time - O(N);
	Space - O(N);	
*/		 


void inorder(TreeNode* root, vector<int>&inorderRes) {
	stack<TreeNode*>treeStack;
	TreeNode* current = root;

	while(1) {
		while(current) {
			treeStack.push(current);
			current = current->left;
		}

		if(treeStack.empty()) break;

		current = treeStack.top();
		treeStack.pop();

		inorderRes.push_back(current->val);
		current = current->right;
	}
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>inorderRes;

	inorder(root, inorderRes);
	for(int x : inorderRes) cout << x << " ";
	return 0; 
} 
