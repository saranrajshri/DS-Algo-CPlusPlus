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
	Top View
	Approach - Level Order + Vertical Order Traverse
	Time - O(n);
	Space - O(n);
*/		

void fillMap(TreeNode* root, int verticalDistance, int currentLevel, map<int, pair<int, int>> &visited) {
	if(root) {
		if(visited.count(verticalDistance) == 0) {
			visited[verticalDistance] = make_pair(root->val, currentLevel);
		}
		else if(currentLevel > visited[verticalDistance].second) {
			visited[verticalDistance] = make_pair(root->val, currentLevel);
		}

		fillMap(root->left, verticalDistance - 1, currentLevel + 1, visited);
		fillMap(root->right, verticalDistance + 1, currentLevel + 1, visited);
	}
}

vector<int> bottomView(TreeNode* root) {
	map<int, pair<int, int>>visited;
	vector<int>res;

	// 0 - Vertical distance from the root
	// 0 - Current Level of the node
	fillMap(root, 0, 0, visited);

	for(auto it = visited.begin(); it != visited.end(); it++) {
		res.push_back(it->second.first);
	}
	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<int>res = bottomView(root);	

	for(int x : res) cout << x << " ";
	return 0; 
} 