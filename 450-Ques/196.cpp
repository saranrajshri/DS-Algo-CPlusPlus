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

TreeNode* constructBinaryTree() {
	
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

TreeNode* constructNewBinaryTree() {
	
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

void inorder(TreeNode* root, std::vector<int> &res) {
	if(root == NULL) return;
	inorder(root->left, res);
	res.push_back(root->val);
	inorder(root->right, res);
}

void mergeTwoArrays(std::vector<int> arr1, std::vector<int>arr2, std::vector<int>&res) {
	int i = 0;
	int j = 0;
	int k = 0;

	while(i < arr1.size() && j < arr2.size()) {
		if(arr1[i] < arr2[j]) {
			res[k++] = arr1[i++];
		}else{
			res[k++] = arr2[j++];
		}
	}

	while(i < arr1.size()) {
		res[k++] = arr1[i++];
	}

	while(j < arr2.size()) {
		res[k++] = arr2[j++];
	}
}

TreeNode* helper(std::vector<int>arr, int left, int right) {
	if(left > right) return NULL;

	int mid = left + (right - left) / 2;

	TreeNode* currentNode = createNewNode(arr[mid]);
	currentNode->left = helper(arr, left, mid - 1);
	currentNode->right = helper(arr, mid + 1, right);

	return currentNode;
}

TreeNode* constructBST(std::vector<int>arr) {
	return helper(arr, 0, arr.size() - 1);
}

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
	std::vector<int>inOrder1;
	std::vector<int> inOrder2;

	inorder(root1, inOrder1);
	inorder(root2, inOrder2);

	std::vector<int> mergedArray(inOrder1.size() + inOrder2.size());

	mergeTwoArrays(inOrder1, inOrder2, mergedArray);

	// for(int x : mergedArray) std::cout << x << " ";
	
	TreeNode* root = constructBST(mergedArray);

	return root;
}

int main() { 
	TreeNode* root1 = constructBinaryTree();
	TreeNode* root2 = constructNewBinaryTree();
	
	TreeNode* newRoot = mergeBST(root1, root2);
	
	std::vector<int>res;

	inorder(newRoot, res);
	for(int x : res) std::cout << x << " ";
	return 0; 
} 