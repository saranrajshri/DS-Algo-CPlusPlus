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
	Space - O(n);	
*/		


int largestSubTreeSumHelper(TreeNode* root, int &ans) {
	if(root == NULL) return 0;

	int currentSum = root->val + largestSubTreeSumHelper(root->left, ans) + largestSubTreeSumHelper(root->right, ans); 

	ans = max(ans, currentSum);

	return ans;
}

int largestSubTreeSum(TreeNode* root) {
	int ans = INT_MIN;
	
	largestSubTreeSumHelper(root, ans);

	return ans;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	cout << largestSubTreeSum(root);	
	return 0; 
} 