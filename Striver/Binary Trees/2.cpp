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
	stack<TreeNode*> s;
	s.push(root);
	vector<int> res;

	while(!s.empty()) {
		TreeNode* topNode = s.top();
		s.pop();

		res.push_back(topNode->val);

		if(topNode->right) {
			s.push(topNode->right);
		}

		if(topNode->left) {
			s.push(topNode->left);
		}
	}	

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int> res = solve(root);

	for(int x : res) cout << x << " ";
	return 0; 
} 