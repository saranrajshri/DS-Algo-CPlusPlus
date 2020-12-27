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

vector<vector<int>> solve(TreeNode* root) {
	vector<vector<int>> res;
	queue<TreeNode*> q;

	q.push(root);
	bool isReverse = false;

	while(!q.empty()) {
		int size = q.size();
		vector<int> currentRow(size);

		for(int i = 0; i < size; i++) {
			TreeNode* currentNode = q.front();
			q.pop();
			
			int index = isReverse ? size - i - 1 : i;
			currentRow[index] = currentNode->val;

			if(currentNode->left) q.push(currentNode->left);
			if(currentNode->right) q.push(currentNode->right);
		}
		isReverse = !isReverse;
		res.push_back(currentRow);
	}

	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<vector<int>> res = solve(root);

	for(auto it : res) {
		for(int x : it) cout << x << " ";
		cout << endl;
	}	
	return 0; 
} 