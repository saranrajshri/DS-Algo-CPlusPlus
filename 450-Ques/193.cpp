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

TreeNode* constructBSTHelper(std::vector<int> preorder, int &index, int key, long low, long high) {
	if(index >= preorder.size()) return NULL;

	TreeNode* root = NULL;

	if(key > low && key < high) {
		root = createNewNode(key);
		index++;

		if(index < preorder.size()) {
			root->left = constructBSTHelper(preorder, index, preorder[index], low, key);
		}

		if(index < preorder.size()) {
			root->right = constructBSTHelper(preorder, index, preorder[index], key, high);
		}
	}

	return root;
}

TreeNode* constructBST(std::vector<int>preorder) {
	int index = 0;
	return constructBSTHelper(preorder, index, preorder[0], LONG_MIN, LONG_MAX);
}


int main(){	

	std::vector<int>preorder = {10, 5, 1, 7, 40, 50};
	TreeNode* root = constructBST(preorder);
	inorder(root);
	return 0;
}
