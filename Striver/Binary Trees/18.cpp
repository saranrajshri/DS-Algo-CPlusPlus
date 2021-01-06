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

void solve(TreeNode* root, TreeNode* head) {
	if(root == NULL) return;

	solve(root->left, head);

	static TreeNode* prev = NULL;

	if(prev == NULL) {
		head = root;
	}else{
		root->left = prev;
		prev->right = root;
	}

	prev = root;

	solve(root->right, head);
}

int main() { 
	TreeNode* root = constructBinaryTree();
	solve(root);	
	return 0; 
} 