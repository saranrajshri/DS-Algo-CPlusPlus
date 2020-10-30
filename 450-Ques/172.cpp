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
	
	TreeNode* root = new TreeNode(10); 
	root->left = new TreeNode(-2); 
	root->right	= new TreeNode(6); 
	root->left->left = new TreeNode(8); 
	root->left->right = new TreeNode(-4);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(5); 

	return root;
}

/*
	Time - O(N);
	Space - O(n);
*/		

TreeNode* sumTree(TreeNode* root) {
	if(root == NULL) return 0;

	int tempVal = root->val;

	root->val = sumTree(root->left) + sumTree(root->right);

	return tempVal + root->val;
}

void inorder(TreeNode* root) {
	if(root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

int main() { 
	TreeNode* root = constructBinaryTree();
	TreeNode* sumTreeRoot = sumTree(root);
	inorder(sumTreeRoot);
	return 0; 
} 