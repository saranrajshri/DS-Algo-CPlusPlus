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

std::vector<std::pair<int, int>> findPairs(TreeNode* root1, TreeNode* root2, int target) {
	std::vector<std::pair<int, int>>res;
	std::vector<int> inOrder1;
	std::vector<int> inOrder2;

	inorder(root1, inOrder1);
	inorder(root2, inOrder2);

	int left = 0;
	int right = inOrder2.size() - 1;

	int currentSum = 0;

	while(left < inOrder1.size() && right >= 0) {
		currentSum = inOrder1[left] + inOrder2[right];

		if(currentSum < target) left++;
		else if(currentSum > target) right--;
		else{
			res.push_back(std::make_pair(inOrder1[left], inOrder2[right]));
			left++;
			right--;
		}
	} 

	return res;
} 

int main() { 
	TreeNode* root1 = constructBinaryTree();
	TreeNode* root2 = constructNewBinaryTree();
	
	int target = 130;
	std::vector<std::pair<int, int>> arr = findPairs(root1, root2, target);	

	for(std::pair<int, int> p : arr) {
		std::cout << p.first << " " << p.second << std::endl;
	}
	return 0; 
} 