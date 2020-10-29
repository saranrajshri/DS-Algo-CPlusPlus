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
	Space - O(H); - Height of the tree
*/		

void leftBoundary(TreeNode* root) {
	if(root->left) {
		cout << root->val << " ";
		leftBoundary(root->left);
	}else if(root->right) {
		cout << root->val << " ";
		leftBoundary(root->right);
	}
}

void rightBoundary(TreeNode* root) {
	if(root->right) {
		cout << root->val << " ";
		rightBoundary(root->right);
	}else if(root->left) {
		cout <<  root->val << " ";
		rightBoundary(root->left);
	}
}


void leafNodes(TreeNode* root) {
	if(root) {
		leafNodes(root->left);
		if(!(root->left) && !(root->right)) {
			cout << root->val <<  " ";
		}
		leafNodes(root->right);
 	}
}

void boundaryTraverse(TreeNode* root) {
	leftBoundary(root);
	rightBoundary(root);
	leafNodes(root);
}

int main() { 
	TreeNode* root = constructBinaryTree();
	boundaryTraverse(root);	
	return 0; 
} 