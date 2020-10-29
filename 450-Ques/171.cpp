#include <bits/stdc++.h> 
using namespace std; 

/*
	Binary Tree
	Template from geek for geeks
*/		

struct TreeNode { 
	int val; 
	struct TreeNode* left, *right; 

	TreeNode(int data) { 
		this->val = data; 
		left = right = NULL; 
	} 
}; 


TreeNode* constructBinaryTree() {
	
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(2); 
	root->right	= new TreeNode(3); 
	root->left->left = new TreeNode(4); 
	root->left->right = new TreeNode(5); 

	return root;
}
/*
	
*/		

int findCloseParanIndex(string str, int leftIndex, int rightIndex) {
	if(leftIndex > rightIndex) return -1;

	stack<char>s;

	for(int currentIndex = leftIndex; currentIndex <= rightIndex; currentIndex++) {
		if(str[currentIndex] == '(') s.push('(');
		else if(str[currentIndex] == ')') {
			if(s.top() == '(') {
				s.pop();
				if(s.empty()) return currentIndex;
			}
		}
	}

	return -1;
}

TreeNode* constructTree(string str, int leftIndex, int rightIndex) {
	if(leftIndex > rightIndex) return NULL;

	TreeNode* newNode = new TreeNode(-1);
	newNode->val = str[leftIndex] - '0';
	newNode->left = NULL;
	newNode->right = NULL;

	int closeParanIndex = -1;

	if(leftIndex + 1 < rightIndex && str[leftIndex + 1] == '(') {
		closeParanIndex = findCloseParanIndex(str, leftIndex + 1, rightIndex);
	}

	if(closeParanIndex != -1) {
		newNode->left = constructTree(str, leftIndex + 2, closeParanIndex - 1);
		
		newNode->right = constructTree(str, closeParanIndex + 2, rightIndex - 1);
	}

	return newNode;
}

void inorder(TreeNode* root) {
	if(root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

int main() { 
	string str = "4(2(3)(1))(6(5))";
	TreeNode* root = constructTree(str, 0, str.size() - 1);	
	inorder(root);
	return 0; 
} 