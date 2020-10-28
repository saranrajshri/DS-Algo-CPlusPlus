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
	Approach - Iterative;
	Time - O(n);
	Space - O(N);
*/		

void postOrder(TreeNode* root, vector<int>& postOrderRes) {
	stack<TreeNode*> treeStack1;
	stack<TreeNode*> treeStack2;

	treeStack1.push(root);

	while(!treeStack1.empty()) {
		TreeNode* topElement = treeStack1.top();
		treeStack1.pop();

		treeStack2.push(topElement);
		if(topElement->left)
			treeStack1.push(topElement->left);
		if(topElement->right)
			treeStack1.push(topElement->right);
	}

	while(!treeStack2.empty()) {
		postOrderRes.push_back(treeStack2.top()->val);
		treeStack2.pop();
	}
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>postOrderRes;

	postOrder(root, postOrderRes);
	for(int x : postOrderRes) cout << x << " ";
	return 0; 
} 