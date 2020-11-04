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
	if (root != NULL) {
		inorder(root->left);
		std::cout << root->val << " ";
		inorder(root->right);
	}
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

/*
	Time - O(log N);
	Space - O(log N);
*/		

TreeNode* maxValue(TreeNode* root) {
	if(root == NULL) return NULL;

	TreeNode* currentNode = root;
	while(currentNode->right) {
		currentNode = currentNode->right;
	}

	return currentNode;
}

TreeNode* deleteNode(TreeNode* root, int valToBeDeleted) {
	if(root == NULL) return NULL;

	if(valToBeDeleted < root->val) {
		root->left = deleteNode(root->left, valToBeDeleted);
	}
	else if(valToBeDeleted > root->val) {
		root->right = deleteNode(root->right, valToBeDeleted);
	}else{
		if(root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* tempVal = maxValue(root->right);
		root->val = tempVal->val;

		root->right = deleteNode(root->right, tempVal->val);
	}

	return root;

}

int main(){	
	TreeNode* root = constructBST();
	inorder(root);
	std::cout << std::endl;
	deleteNode(root, 70);
	inorder(root);
	return 0;
}
