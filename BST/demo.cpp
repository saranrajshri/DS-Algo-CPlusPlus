#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// Create a new node
struct TreeNode* newNode(int val) {

	struct TreeNode* currentNode = 	(struct TreeNode*)malloc(sizeof(struct TreeNode));
	currentNode->val = val;
	currentNode->left = NULL;
	currentNode->right = NULL;	

	return currentNode;
}

// Insert a node to the BST
struct TreeNode* insert(TreeNode* root, int val) {
	if(root == NULL) newNode(val);

	if(val < root->val) {
		root->left = insert(root->left, val);
	}else if (val > root->val) {
		root->right = insert(root->right, val);
	}

	return root;
}

// Inorder Traversal
void inorder(TreeNode* root){
	if(root != NULL){
		inorder(root->left);
		cout << root->val << endl;
		inorder(root->right);
	}
}

// post order Traversal
void postOrder(TreeNode *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << endl;
	}
}

// PreOrder
void preOrder(TreeNode *root){
	if(root != NULL){
		cout << root->val << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main() {
	struct TreeNode* root = NULL;
	root = insert(root, 50);
	insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
	
	inorder(root);
	return 0;
}