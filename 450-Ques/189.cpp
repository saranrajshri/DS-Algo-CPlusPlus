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

/*
	Time - O(N);
	Space - O(n);

*/		

TreeNode* inorderPredecessor(TreeNode* root, int val) {
	if(root == NULL) return NULL;

	if(root->val == val) {
		if(root->left) {
			TreeNode* current = root->left;
			while(current && current->right) {
				current = current->right;
			}

			return current;
		}
	}
	else if(val < root->val) {
		return inorderPredecessor(root->left, val);
	}else if(val > root->val) {
		return inorderPredecessor(root->right, val);
	}

	return NULL;
}


TreeNode* inorderSuccessor(TreeNode* root, int val) {
	if(root == NULL) return NULL;

	if(root->val == val) {
		if(root->right) {
			TreeNode* current = root->right;
			while(current && current->left) {
				current = current->left;
			}

			return current;
		}
	}
	else if(val < root->val) {
		return inorderSuccessor(root->left, val);
	}else if(val > root->val) {
		return inorderSuccessor(root->right, val);
	}

	return NULL;
}




int main(){	
	TreeNode* root = constructBST();
	TreeNode* inOrderPred = inorderPredecessor(root, 70);
	TreeNode* inOrderSucc = inorderSuccessor(root, 70);

	std::cout <<  inOrderPred->val << std::endl;
	std::cout << inOrderSucc->val << std::endl;
	
	return 0;
}
