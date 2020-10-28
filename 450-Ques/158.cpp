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
	Using Queue
	Time - O(N);
	Space - O(N);
*/		

void levelOrderTraverse(TreeNode* root, vector<vector<int>>& result) {
	queue<TreeNode*>q;
	q.push(root);

	while(!q.empty()) {
		int size = q.size();
		vector<int> currentLevel(size);
		for(int i = 0; i < size; i++) {
			TreeNode* currentNode = q.front();
			q.pop();

			currentLevel[i] = currentNode->val;
			if(currentNode->left) q.push(currentNode->left);
			if(currentNode->right) q.push(currentNode->right);
		}
		result.push_back(currentLevel);
	}
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<vector<int>>result;

	levelOrderTraverse(root, result);	
	for(auto array : result) {
		for(int x : array) cout << x << " ";
		cout << endl;
	}
	return 0; 
} 