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
	root->left = new TreeNode(20); 
	root->right	= new TreeNode(30); 
	root->left->left = new TreeNode(10); 
	root->left->right = new TreeNode(10); 

	return root;
}

/*
	Approach - Un optimized Method
	Time - O(N ^ 2);
	Space - O(N ^ 2);
*/		

int sumTree(TreeNode* root) {
	if(root == NULL) return 0;

	return sumTree(root->left) + root->val + sumTree(root->right);
}

int isSumTree(TreeNode* root) {
	if(root == NULL) return 1;

	if(root->left == NULL && root->right == NULL) return 1;

	int leftSum = sumTree(root->left);
	int rightSum = sumTree(root->right);

	if(root->val == (leftSum + rightSum) && isSumTree(root->left) && isSumTree(root->right)) return 1;

	return 0;
}

/*
	Approach 2 - Optimal 		
	Time - O(n);
	Space - O(N);
*/		 	

int isLeaf(TreeNode* root) {
	if(root == NULL) return 0;

	if(root->left == NULL && root->right == NULL) return 1;

	return 0;
}

int isSumTree(TreeNode* root) {
	if(root == NULL || isLeaf(root)) return 0;

	int leftSum, rightSum;

	if(isSumTree(root->left) && isSumTree(root->right)) {
		if(root->left == NULL) {
			leftSum = 0;
		}else if(isLeaf(root->left)) {
			leftSum = root->left->val;
		}else{
			leftSum = 2 * root->left->val;
		}

		if(root->right == NULL) {
			rightSum = 0;
		}else if(isLeaf(root->right)) {
			rightSum = root->right->val;
		}else{
			rightSum = 2 * root->right->val;
		}
	}
	if(root->data == leftSum + rightSum) return 1;

	return 0;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	if(isSumTree(root)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
} 