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

void longestPathHelper(TreeNode* root, int currentSum, int &maxSum, int currentLength, int &maxLength) {
	if(root == NULL) {
		if(currentLength > maxLength) {
			maxLength = currentLength; 
			maxSum = currentSum;
		}else if(currentLength == maxLength && currentSum > maxSum) {
			maxSum = currentSum;
			maxLength = currentLength;
		}
		return;
	}

	longestPathHelper(root->left, currentSum + root->val, maxSum, currentLength + 1, maxLength);
	longestPathHelper(root->right, currentSum + root->val, maxSum, currentLength + 1, maxLength);
}

int longestPath(TreeNode* root) {
	int maxLength = INT_MIN;
	int maxSum = INT_MIN;

	longestPathHelper(root, 0, maxSum, 0, maxLength);

	return maxSum;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	cout << longestPath(root) << endl;	
	return 0; 
} 