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
	Time - O(n);
	Space - O(N);
*/		
	
vector<vector<int>> zigZagTraverse(TreeNode* root) {
	bool leftToRight = true;
	queue<TreeNode*>q;
	vector<vector<int>>res;
	q.push(root);

	while(!q.empty()) {
		int size = q.size();
		vector<int>currentLevel(size);

		for(int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			q.pop();

			int index;
			index = leftToRight ? i : size - i - 1;
			currentLevel[index] = current->val;

			if(current->left) q.push(current->left);
			if(current->right) q.push(current->right);
		}	

		res.push_back(currentLevel);

		leftToRight = !leftToRight;
	}
	return res;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	vector<vector<int>>res = zigZagTraverse(root);
	for(auto array : res) {
		for(int x : array) cout << x << " ";
	}	
	return 0; 
} 