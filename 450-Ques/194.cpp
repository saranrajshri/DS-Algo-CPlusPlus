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
} ; 


TreeNode* constructBinaryTree() {
	
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(2); 
	root->right	= new TreeNode(3); 
	root->left->left = new TreeNode(4); 
	root->left->right = new TreeNode(5); 

	return root;
}

void inorder(TreeNode* root, vector<int>&inOrderRes) {
	if(root == NULL) return;

	inorder(root->left, inOrderRes);
	inOrderRes.push_back(root->val);
	inorder(root->right, inOrderRes);
}

void arrayToBST(TreeNode* root, vector<int>inOrderRes, int &index) {
	if(root == NULL) return;

	arrayToBST(root->left, inOrderRes, index);
	
	root->val = inOrderRes[index++];
	
	arrayToBST(root->right, inOrderRes, index);

}

void convertToBST(TreeNode* root) {
	vector<int> inOrderRes;
	inorder(root, inOrderRes);

	sort(inOrderRes.begin(), inOrderRes.end());

	int index = 0;

	arrayToBST(root, inOrderRes, index);
}

int main() { 
	TreeNode* root = constructBinaryTree();

	vector<int> res;
	inorder(root, res);
	
	for(int x : res) cout << x << " ";
	
	cout << endl;
	convertToBST(root);	

	vector<int>newRes;

	inorder(root,newRes);
	for(int x : newRes) cout << x << " ";

	return 0; 
} 