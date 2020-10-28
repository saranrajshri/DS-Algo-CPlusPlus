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
	Approach - Recursive
	Time - O(N);
	Space - O(N);
*/		

void preOrder(TreeNode* root, vector<int>& preOrderRes) {
	if(root) {
		preOrderRes.push_back(root->val);
		preOrder(root->left, preOrderRes);
		preOrder(root->right, preOrderRes);
	}
}

/*
	Approach - Iterative
	Time - O(N);
	Space - O(N);
*/		

void preOrder(TreeNode* root, vector<int>& preOrderRes) {
	stack<TreeNode*> treeStack;
	treeStack.push(root);

	while(!treeStack.empty()) {
		TreeNode* topElement = treeStack.top();
		treeStack.pop();

		preOrderRes.push_back(topElement->val);

		if(topElement->right) {
			treeStack.push(topElement->right);
		} 
		if(topElement->left) {
			treeStack.push(topElement->left);
		}
	}
}


int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>preOrderRes;

	preOrder(root, preOrderRes);
	for(int x : preOrderRes) cout << x << " ";
	return 0; 
} 