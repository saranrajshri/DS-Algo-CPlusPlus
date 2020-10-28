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
	Time - O(N);
	Space - O(N);
*/		

vector<int> reverseLevelOrderTraversal(TreeNode* root) {
	vector<int>res;
	queue<TreeNode*>q;
	stack<TreeNode*>s;

	q.push(root);
	while(!q.empty()) {
		TreeNode* current = q.front();
		q.pop();

		s.push(current);

		if(current->right) q.push(current->right);
		if(current->left) q.push(current->left);
	}

	while(!s.empty()) {
		res.push_back(s.top()->val);
		s.pop();
	}

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>res = reverseLevelOrderTraversal(root);

	for(int x : res) cout << x << " ";	
	return 0; 
} 