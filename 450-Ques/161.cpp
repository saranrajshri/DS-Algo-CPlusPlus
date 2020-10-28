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
	Diameter of Tree
	Time - O(N);
	Space - O(N);
*/		

int height(TreeNode* root, int &ans) {
	if(root == NULL) return 0;

	int leftHeight = height(root->left, ans);
	int rightHeight = height(root->right, ans);

	ans = max(ans, leftHeight + rightHeight + 1);

	return max(leftHeight, rightHeight) + 1;
}

int diameterOfTree(TreeNode* root) {
	if(root == NULL) return 0;

	int diameter = INT_MIN;
	int heightOfTree = height(root, diameter);

	return diameter;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	cout << diameterOfTree(root);	
	return 0; 
} 