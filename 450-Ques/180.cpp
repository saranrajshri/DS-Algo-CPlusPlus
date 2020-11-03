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

TreeNode* lowestCommonAncestor(TreeNode* root, int q1, int q2) {
	if(root == NULL) return NULL;

	if(root->val == q1 || root->val == q2) return root;

	TreeNode* left = lowestCommonAncestor(root->left, q1, q2);
	TreeNode* right = lowestCommonAncestor(root->right, q1, q2);


	if(left && right) return root;

	return left ? left : right;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	TreeNode* lca = lowestCommonAncestor(root, 4, 5);

	cout << lca->val << endl;	
	return 0; 
} 