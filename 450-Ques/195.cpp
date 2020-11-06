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

void inorder(TreeNode* root, vector<int>& inOrderRes) {
	if(root == NULL) return;

	inorder(root->left);
	inOrderRes.push_back(root->val);
	inorder(root->right);
}

TreeNode* helper(vector<int> inOrderRes, int left, int right) {
	if(left > right) return NULL;

	int mid = left + (right - left) / 2;
	TreeNode* currentNode = new TreeNode(inOrderRes[mid]);
	currentNode->left = helper(inOrderRes, left, mid - 1);
	currentNode->right = helper(inOrderRes, mid + 1, right);

	return currentNode;
}

TreeNode* newBST(vector<int> inOrderRes) {
	return helper(inOrderRes, 0, inOrderRes.size() - 1);
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>inOrderRes;

	inorder(root, inOrderRes);	
	TreeNode* newBST = constructBST(inOrderRes);
	return 0; 
} 