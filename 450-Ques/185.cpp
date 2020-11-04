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

	TreeNode* root = new TreeNode(26);  
    root->right         = new TreeNode(3);  
    root->right->right = new TreeNode(3);  
    root->left         = new TreeNode(10);  
    root->left->left     = new TreeNode(4);  
    root->left->left->right = new TreeNode(30);  
    root->left->right     = new TreeNode(6); 

	return root;
}

TreeNode* constructNewBinaryTree() {

	TreeNode* root = new TreeNode(10);  
    root->right     = new TreeNode(6);  
    root->left     = new TreeNode(4);  
    root->left->right = new TreeNode(30); 

    return root;
}

/*
	Time - Worst Case O(MN);
	Space - O(MN);
*/		

bool areIdentical(TreeNode* treeRoot, TreeNode* subTreeRoot) {
	if(treeRoot == NULL && subTreeRoot == NULL) return true;

	if(treeRoot == NULL || subTreeRoot == NULL) return false;

	return treeRoot->val == subTreeRoot->val && areIdentical(treeRoot->left, subTreeRoot->left) && areIdentical(treeRoot->right, subTreeRoot->right);
}

bool isSubTree(TreeNode* treeRoot, TreeNode* subTreeRoot) {
	if(subTreeRoot == NULL) return true;
	if(treeRoot == NULL) return false;

	if(areIdentical(treeRoot, subTreeRoot)) return true;

	return isSubTree(treeRoot->left, subTreeRoot) || isSubTree(treeRoot->right, subTreeRoot);
}

int main() { 
	TreeNode* root = constructBinaryTree();
	TreeNode* subTreeRoot = constructNewBinaryTree();

	if(isSubTree(root, subTreeRoot)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0; 
} 