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

int heightOfTree(TreeNode* root) {
	if(root == NULL) return 0;

	int leftHeight = heightOfTree(root->left);
	int rightHeight = heightOfTree(root->right);

	return max(leftHeight, rightHeight) + 1;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	cout << heightOfTree(root);
	return 0; 
} 