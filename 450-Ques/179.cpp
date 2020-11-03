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
	root->left = new TreeNode(3); 
    root->left->left = new TreeNode(2); 
    root->left->right = new TreeNode(1); 
    root->left->right->left = new TreeNode(1); 
    root->right = new TreeNode(-1); 
    root->right->left = new TreeNode(4); 
    root->right->left->left = new TreeNode(1); 
    root->right->left->right = new TreeNode(2); 
    root->right->right = new TreeNode(5); 
    root->right->right->right = new TreeNode(2); 
  

	return root;
}

/*
	Time - O(N ^ 2);
	Space - O(N);	
*/		

void pushToVector(vector<int>path, int index, vector<vector<int>> &res) {
	vector<int>currentPath;

	for(int i = index; i < path.size(); i++) {
		currentPath.push_back(path[i]);
	}

	res.push_back(currentPath);
}

void findPathHelper(TreeNode* root, int k, vector<int>&path, vector<vector<int>>&res) {
	if(root == NULL) return;

	path.push_back(root->val);

	findPathHelper(root->left, k, path, res);
	findPathHelper(root->right, k, path, res);

	int currentPathSum = 0;

	for(int i = path.size() - 1; i >= 0; i--) {
		currentPathSum += path[i];

		if(currentPathSum == k) {
			pushToVector(path, i, res);
		}
	}

	path.pop_back();
}
 
vector<vector<int>> findKSumPaths(TreeNode* root, int k) {
	vector<vector<int>> res;
	vector<int>path;

	findPathHelper(root, k, path, res);

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	int k = 5;
	vector<vector<int>> res = findKSumPaths(root, k);

	for(auto arr : res) {
		for(int x : arr) cout << x << " ";
		cout << endl;
	}	
	return 0; 
} 