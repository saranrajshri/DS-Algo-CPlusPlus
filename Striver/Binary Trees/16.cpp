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

TreeNode* helper(vector<int> inOrder, vector<int> postOrder, int &index, int start, int end, unordered_map<int, int> m) {
	if(start > end) return NULL;

	TreeNode* currentNode = new TreeNode(postOrder[index]);
	int nextIndex = m[postOrder[index--]];

	currentNode->right = helper(inOrder, postOrder, index, nextIndex + 1, end, m);
	currentNode->left = helper(inOrder, postOrder, index, start, nextIndex - 1, m);

	return currentNode;
}

TreeNode* constructBinaryTree(vector<int> inOrder, vector<int> postOrder) {
	unordered_map<int, int> m;

	for(int i = 0; i < inOrder.size(); i++) m[inOrder[i]] = i;

	int index = postOrder.size() - 1;

	return helper(inOrder, postOrder, index, 0, inOrder.size() - 1, m);
}

void inorder(TreeNode* root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main() { 
	vector<int> inOrder = {9,3,15,20,7};
	vector<int> postOrder = {9,15,7,20,3};
	TreeNode* root = constructBinaryTree(inOrder, postOrder);
	inorder(root); 
	return 0; 
} 