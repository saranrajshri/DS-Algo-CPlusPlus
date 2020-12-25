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

// void inorder(TreeNode* root, vector<int>&inorderRes) {
// 	if(root == NULL) return;

// 	inorder(root->left, inorderRes);
// 	inorderRes.push_back(root->val);
// 	inorder(root->right, inorderRes);
// }

vector<int> solve(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> res;

	TreeNode* currentNode = root;

	while(1) { 	
		while(currentNode) {
			s.push(currentNode);
			currentNode = currentNode->left;
		}

		if(s.empty()) break;
		currentNode = s.top();
		s.pop();

		res.push_back(currentNode->val);

		currentNode = currentNode->right;
	}	

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	// vector<int> inorderRes;

	// inorder(root, inorderRes);

	vector<int> inorderRes = solve(root);

	for(int x : inorderRes) cout << x << " ";	
	return 0; 
} 