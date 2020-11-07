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
	
	TreeNode* root = new TreeNode(3); 
	root->left = new TreeNode(1); 
	root->right	= new TreeNode(4); 

	return root;
}

struct NodeInfo{
	int size;
	int minVal;
	int maxVal;
	int ans;
	bool isBST;
};

/*
	Time - O(N);
	Space - O(N);
*/		

NodeInfo largestBST(TreeNode* root) {
	if(root == NULL) {
		return {0, INT_MIN, INT_MAX, 0, true};
	}

	if(root->left == NULL && root->right == NULL) {
		return {1, root->val, root->val, 1, true};
	}

	NodeInfo leftBST = largestBST(root->left);
	NodeInfo rightBST = largestBST(root->right);

	NodeInfo ansNode;
	ansNode.size = leftBST.size + rightBST.size + 1;

	if(leftBST.isBST && rightBST.isBST && root->val > leftBST.minVal &&  root->val < rightBST.maxVal) {
		ansNode.minVal = min(leftBST.minVal, min(rightBST.minVal, root->val));
		ansNode.maxVal = max(leftBST.maxVal, max(rightBST.maxVal, root->val));

		ansNode.isBST = true;
		ansNode.ans = ansNode.size;

		return ansNode;
	}

	ansNode.isBST = false;
	ansNode.ans = max(leftBST.ans, rightBST.ans);

	return ansNode;
	
}

int main() { 
	TreeNode* root = constructBinaryTree();
	NodeInfo res = largestBST(root);	
	cout << res.ans << endl;
	return 0; 
} 