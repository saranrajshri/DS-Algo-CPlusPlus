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

bool isAllLevelSame(TreeNode* root, int currentLevel, int &maxLevel) {
	if(root == NULL) return true;

	if(root->left == NULL && root->right == NULL) {
		if(maxLevel == 0) {
			maxLevel = currentLevel;
			return true;
		}

		return (currentLevel == maxLevel);
	}

	return isAllLevelSame(root->left, currentLevel + 1, maxLevel) && isAllLevelSame(root->right, currentLevel + 1, maxLevel);
}

int main() { 
	TreeNode* root = constructBinaryTree();
	int maxLevel = 0;

	if(isAllLevelSame(root, 0, maxLevel)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0; 
} 