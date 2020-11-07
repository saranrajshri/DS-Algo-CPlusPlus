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

/* A utility function to insert a new node with given key in BST */
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
	
	TreeNode *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	return root;
}

void inorder(TreeNode* root, TreeNode* prev) {
	if(root == NULL) return;

	inorder(root->left, prev);
	prev->left = NULL;
	prev->right = root;

	prev = root;
	inorder(root->right, prev);
}

void flatten(TreeNode* root) {
	TreeNode* dummy = createNewNode(-1);
	TreeNode* prev = dummy;

	inorder(root, prev);

	prev->left = NULL;
	prev->right = NULL;

	TreeNode* res = dummy->right;

	while(res) {
		std::cout << res->val << " ";
		res = res->right;
	}

}

int main(){	

	TreeNode* root = constructBST();
	flatten(root);
	return 0;
}
