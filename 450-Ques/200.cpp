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
void inorder(TreeNode* root, std::vector<int>& res) {
	if (root != NULL)
	{
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
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

int findMedian(std::vector<int> arr) {
	if(arr.size() % 2 != 0) {
		return arr[arr.size() / 2];
	}
	
	return arr[(arr.size() - 1 / 2) + (arr.size() / 2)] / 2;  
}


int main(){	

	TreeNode* root = constructBST();
	std::vector<int> inorderRes;

	inorder(root, inorderRes);
	std::cout << findMedian(inorderRes);
	return 0;
}
