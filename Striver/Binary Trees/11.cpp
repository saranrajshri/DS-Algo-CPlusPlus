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

TreeNode* solve(TreeNode* root, int p1, int p2) {
	if(root == NULL) return NULL;

	if(root->val == p1 || root->val == p2) {
		return root;
	}

	TreeNode* leftNode = solve(root->left, p1, p2);
	TreeNode* rightNode = solve(root->right, p1, p2);

	if(leftNode && rightNode) return root;

	return leftNode ? leftNode : rightNode;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	TreeNode* lcaNode = solve(root, 3, 5);
	cout << lcaNode->val << endl; 	
	return 0; 
} 