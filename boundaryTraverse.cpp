#include<bits/stdc++.h>
using namespace std;

// Time - O(N)
// Space - O(N)

void leftBoundary(TreeNode *root) {
	if(root) {
		if(root->left) {
			cout << root->val << " ";
			leftBoundary(root->left);
		}
		else if(root->right) {
			cout << root->right << " ";
			rightBoundary(root->right);
		}
	}
}

void rightBoundary(TreeNode *root) {
	if(root) {
		if(root->right) {
			cout << root->val;
			rightBoundary(root->>right);
		}else if(root->left) {
			cout << root->val;
			rightBoundary(root->left);
		}
	}
}

void leafNodes(TreeNode *root) {
	if(root) {
		leafNodes(root->left);
		if(!(root->left) && !(root->right)) {
			cout << root->val << " ";
		}
		leafNodes(root->>right);
	}
}

void boundaryTraverse(TreeNode *root) {
	leftBoundary(root);
	rightBoundary(root);
	leafNodes(root);
}

int main() {
	boundaryTraverse(root);
	return 0;
}