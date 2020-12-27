#include <bits/stdc++.h> 
using namespace std; 

/*
	Binary Tree
	Template from geek for geeks
*/		

struct TreeNode { 
	int val; 
	struct TreeNode* left, *right, *next; 

	TreeNode(int data) { 
		this->val = data; 
		left = right = next = NULL; 
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

// TreeNode* solve(TreeNode* root) {
// 	queue<TreeNode*> q;
// 	q.push(root);
// 	q.push(NULL);

// 	while(!q.empty()) {
// 		TreeNode* currentNode = q.front(); 
// 		q.pop();

// 		if(currentNode == NULL) {
// 			if(q.size() > 0) q.push(NULL);
// 		}else{
// 			currentNode->next = q.front();
// 			if(currentNode->left) q.push(currentNode->left);
// 			if(currentNode->right) q.push(currentNode->right);
// 		}
// 	}

// 	return root;
// }

TreeNode* solve(TreeNode* root) {
	if(root == NULL) return NULL;

	TreeNode* levelStart = root;

	while(levelStart != NULL) {
		TreeNode* currentNode = levelStart;
		while(currentNode != NULL) {
			if(currentNode->left) currentNode->left->next = currentNode->right;
			if(currentNode->right && currentNode->next) currentNode->right->next = currentNode->next->left;

			currentNode = currentNode->next;
		}
		levelStart = levelStart->left;
	}

	return root;
}

int main() { 
	TreeNode* root = constructBinaryTree();
	TreeNode* populatedRoot = solve(root);	
	return 0; 
} 