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

TreeNode* helper(vector<int>preOrder, vector<int> inOrder, int &index, int start, int end, unordered_map<int, int>m) {
	if(start > end) return NULL;

	TreeNode* currentNode = new TreeNode(preOrder[index]);
	int nextIndex = m[preOrder[index++]];

	currentNode->left = helper(preOrder, inOrder, index, start, nextIndex - 1, m);
	currentNode->right = helper(preOrder, inOrder, index, nextIndex + 1, end, m);

	return currentNode;
}

TreeNode* constructBinaryTree(vector<int> preOrder, vector<int> inOrder) {
	unordered_map<int, int> m;

	for(int i = 0; i < inOrder.size(); i++) {
		m[inOrder[i]] = i;
	}
	int index = 0;
	return helper(preOrder, inOrder, index, 0, inOrder.size() - 1, m);
}

void inorder(TreeNode* root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main() { 
	vector<int> preOrder = {3,9,20,15,7};
	vector<int> inOrder = {9,3,15,20,7};

	TreeNode* root = constructBinaryTree(preOrder, inOrder);
	inorder(root);
	return 0; 
} 