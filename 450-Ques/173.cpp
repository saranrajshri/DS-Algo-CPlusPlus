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

int minSwaps(vector<int>arr) {
	vector<pair<int, int>>correctOrderArray;
	vector<bool>visited(arr.size());
	int ans = 0;

	for(int i = 0; i < arr.size(); i++) {
		correctOrderArray.push_back(make_pair(arr[i], i));
	}


	sort(correctOrderArray.begin(), correctOrderArray.end());

	for(int i = 0; i < arr.size(); i++) {
		if(visited[i] || correctOrderArray[i].second == i) continue;

		int cycles = 0;
		int j = i;

		while(!visited[j]) {
			visited[j] = true;
			j = correctOrderArray[j].second;
			cycles++;
		}

		ans += cycles > 0 ? (cycles - 1) : 0;
	}
	return ans;	
}

void inorder(vector<int>arr, vector<int>&newArr, int index) {
	if(index >= arr.size()) return;

	newArr.push_back(arr[index]);

	inorder(arr, newArr, 2 * index + 1);
	inorder(arr, newArr, 2 * index + 2);
}

int main() { 
	vector<int> newArr;
	vector<int>arr = { 5, 6, 7, 8, 9, 10, 11 };
	inorder(arr, newArr, 0);
	cout << minSwaps(newArr);
	return 0; 
} 