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

vector<int> solve(TreeNode* root) {
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	vector<int>res;

	s1.push(root);
	while(!s1.empty()) {
		TreeNode* currentNode = s1.top();
		s1.pop();

		s2.push(currentNode);

		if(currentNode->left) {
			s1.push(currentNode->left);
		}
		if(currentNode->right) {
			s1.push(currentNode->right);
		}
	}

	while(!s2.empty()) {
		res.push_back(s2.top()->val);
		s2.pop();
	}

	return res;
}

// void solve(TreeNode* root) {
// 	if(root == NULL) return;

// 	solve(root->left);
// 	solve(root->right);
// 	cout << root->val << " ";

// }

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int> res = solve(root);
	// solve(root);
	for(int x : res) cout << x << " ";	
	return 0; 
} 