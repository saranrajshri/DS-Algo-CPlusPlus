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

TreeNode* helper(std::vector<int> inOrder, int &index, int left, int right) {
	if(left > right) return NULL;

	int mid = (right - left) + left / 2;
	TreeNode* currentNode = createNewNode(inOrder[mid]);
	currentNode->left = helper(inOrder, index, left, mid - 1);
	currentNode->right = helper(inOrder, index, mid + 1, right);

	return currentNode;
}

TreeNode* solve(std::vector<int> inOrder) {
	int index = 0;
	return helper(inOrder, index, 0, inOrder.size() - 1);
}

int main(){	
	std::vector<int> inOrder = {1, 2, 3, 4};
	TreeNode* root = solve(inOrder);
	inorder(root);
	return 0;
}
