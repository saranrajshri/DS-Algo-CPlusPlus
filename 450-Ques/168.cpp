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

int height(TreeNode* root) {
	
	if(root == NULL) return 0;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
	if(root == NULL) return true;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
		return true;
	} 

	return false;
}


int main() { 
	TreeNode* root = constructBinaryTree();
	if(isBalanced(root)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0; 
} 