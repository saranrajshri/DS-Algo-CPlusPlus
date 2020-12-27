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

void helper(TreeNode* root, int verticalDistance, int currentLevel, map<int, pair<int, int>>&m) {
	if(root == NULL) return;

	if(m.find(verticalDistance) == m.end()) {
		m[verticalDistance] = make_pair(root->val, currentLevel);
	}else if(currentLevel >= m[verticalDistance].second) {
		m[verticalDistance] = make_pair(root->val, currentLevel);
	}

	helper(root->left, verticalDistance - 1, currentLevel + 1, m);
	helper(root->right, verticalDistance + 1, currentLevel + 1, m);
}

vector<int> solve(TreeNode* root) {
	vector<int> res;
	map<int, pair<int, int>> m;

	helper(root, 0, 0, m);

	for(auto it : m) {
		res.push_back(it.second.first);
	}

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int> res = solve(root);

	for(int x : res) cout << x << " ";	
	return 0; 
} 