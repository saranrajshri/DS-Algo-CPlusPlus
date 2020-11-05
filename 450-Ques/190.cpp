#include<bits/stdc++.h>

struct TreeNode{
	int val;
	struct TreeNode *left, *right;
};

// A utility function to create a new BST node
TreeNode* createNewNode(int val) {
	TreeNode* newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));;
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// A utility function to do inorder traversal of BST
void inorder(TreeNode* root) {
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->val << " ";
		inorder(root->right);
	}
}

/* A utility function to insert a createNewNode with given key in BST */
TreeNode* insert(TreeNode* root, int val) {

	if (root == NULL) return createNewNode(val);

	if (val < root->val) {
		root->left = insert(root->left, val);
	}
	else if (val > root->val){
		root->right = insert(root->right, val);
	}

	return root;
}

// Search a value in BST
TreeNode* search(TreeNode* root, int valToBeFound) {
	if(root == NULL || root->val == valToBeFound) return root;
	
	if(valToBeFound < root->val) {
		return search(root->left, valToBeFound);
	}
	
	return search(root->right, valToBeFound);
}

TreeNode* constructBST() {
	
	TreeNode *root = createNewNode(4);  
    root->left = createNewNode(6);  
    root->right = createNewNode(5);  
    root->left->left = createNewNode(1);  
    root->left->right = createNewNode(3);  

	return root;
}

bool isBSTHelper(TreeNode* root, long low, long high) {
	if(root == NULL) return true;

	if(root->val <= low || root->val >= high) return false;

	return isBSTHelper(root->left, low, root->val) && isBSTHelper(root->left, root->val, high);
}

bool isBST(TreeNode* root) {
	return isBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main(){	
	TreeNode* root = constructBST();
	if(isBST(root)) {
		std::cout << "Yes" << std::endl;
	}
	else{
		std::cout << "No" << std::endl;
	}
	return 0;
}
