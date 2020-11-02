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

TreeNode* constructNewBinaryTree() {
	
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(3); 
	root->right	= new TreeNode(2); 
	root->right->left = new TreeNode(5); 
	root->right->right = new TreeNode(4); 

	return root;
}

/*
	Time - O(N);
	Space - O(N);	
*/		

bool isMirror(TreeNode* root1, TreeNode* root2) {
	if(root1 == NULL && root2 == NULL) return true;

	if(root1 == NULL || root2 == NULL) return false;

	return root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

int main() { 
	TreeNode* root1 = constructBinaryTree();
	TreeNode* root2 = constructNewBinaryTree();
		
	if(isMirror(root1, root2)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0; 
} 