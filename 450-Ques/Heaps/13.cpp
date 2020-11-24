// C++ implementation to convert the given 
// BST to Min Heap 
#include <bits/stdc++.h> 
using namespace std; 

// structure of a node of BST 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. */
struct Node* getNode(int data) 
{ 
	struct Node *newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode; 
} 

// function prototype for preorder traversal 
// of the given tree 
void preorderTraversal(Node*); 

// function for the inorder traversal of the tree 
// so as to store the node values in 'arr' in 
// sorted order 
void inorderTraversal(Node *root, vector<int>& arr) {
	if(root) {
		inorderTraversal(root->left, arr);

		arr.push_back(root->data);

		inorderTraversal(root->right, arr);
	}
} 

void buildBST(Node* root, vector<int> inorderArr, int &index) {
	if(root) {
		root->data = inorderArr[index++];
		buildBST(root->left, inorderArr, index);
		buildBST(root->right, inorderArr, index);
	}
}

void convertToMinHeapUtil(Node *root) {
	vector<int>inorderArr;

	inorderTraversal(root, inorderArr);

	int index = 0;
	buildBST(root, inorderArr, index); 
	
} 

// function for the preorder traversal of the tree 
void preorderTraversal(Node *root) 
{ 
	if (!root) 
		return; 

	// first print the root's data 
	cout << root->data << " "; 

	// then recur on left subtree 
	preorderTraversal(root->left); 

	// now recur on right subtree 
	preorderTraversal(root->right); 
} 

// Driver program to test above 
int main() 
{ 
	// BST formation 
	struct Node *root = getNode(4); 
	root->left = getNode(2); 
	root->right = getNode(6); 
	root->left->left = getNode(1); 
	root->left->right = getNode(3); 
	root->right->left = getNode(5); 
	root->right->right = getNode(7); 

	convertToMinHeapUtil(root); 
	cout << "Preorder Traversal:" << endl; 
	preorderTraversal(root); 

	return 0; 
} 
