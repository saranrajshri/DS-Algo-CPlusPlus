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

TreeNode* findPredNode(TreeNode* root) {
	if(root == NULL) return NULL;

	TreeNode* pre = root->left;
	while(pre->right && pre->right != root) {
		pre = pre->right;
	}

	return pre;
}


void solve(TreeNode* root, int k) {
	TreeNode* currentNode = root;
	int count = 0;
	TreeNode* res = NULL;

	while(currentNode) {
		if(currentNode->left == NULL) {
			if(++count == k) res = currentNode;
			std::cout << currentNode->val << " ";
			currentNode = currentNode->right;
		}else{
			TreeNode* preNode = findPredNode(currentNode);
			if(preNode->right == NULL) {
				preNode->right = currentNode;
				currentNode = currentNode->left;
			}
			else{
				preNode->right = NULL;
				if(++count == k) res = currentNode;
				std::cout << currentNode->val << " ";
				currentNode = currentNode->right;
			}
		}
	}
	
	std::cout << std::endl;
	std::cout << res->val << std::endl;
}

int main(){	
	TreeNode* root = constructBST();
	solve(root, 4);
	return 0;
}
