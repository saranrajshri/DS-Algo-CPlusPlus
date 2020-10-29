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

void fillMap(TreeNode* root, int diagonalDistance, map<int, vector<int>> &m) {
	if(root == NULL) return;

	m[diagonalDistance].push_back(root->val);

	fillMap(root->left, diagonalDistance + 1, m);
	fillMap(root->right, diagonalDistance, m);
}
 
void diagonalTraverse(TreeNode* root) {
	map<int, vector<int>>m;

	fillMap(root, 0, m);

	for(auto array : m) {
		for(int x : array.second) cout << x << " ";
		cout << endl;
	}
}


int main() { 
	TreeNode* root = constructBinaryTree();
	diagonalTraverse(root);	
	return 0; 
} 