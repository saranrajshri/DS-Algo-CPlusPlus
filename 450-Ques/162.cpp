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


void inorder(TreeNode* root) {
	if(root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

/*
	Time - O(N);
	Space - O(N);
*/		

void swapLeftAndRight(TreeNode* root) {
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

TreeNode* invertBinaryTree(TreeNode* root) {
	TreeNode* tempRoot = root;

	if(root) {
		swapLeftAndRight(root);
		invertBinaryTree(root->left);
		invertBinaryTree(root->right);
	}

	return tempRoot;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	inorder(root);	
	cout << endl;

	TreeNode* newRoot = invertBinaryTree(root);
	inorder(newRoot);
	return 0; 
} 