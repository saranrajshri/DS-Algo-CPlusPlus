#include<bits/stdc++.h>
using namespace std;

vector<int> levelOrderTraverse(TreeNode* root) {
	queue<TreeNode*> q;
	vector<int> res;
	q.push(root);

	while(!q.empty()) {
		int currentSize = q.size();

		for(int i = 0; i < currentSize; i++) {
			TreeNode* topElement = q.front();
			q.pop();

			res.push_back(topElement->val);

			if(topElement->left) q.push(topElement->left);
			if(topElement->right) q.push(topElement->right);	
		}		
	}

	return res;
}

int main() {
	vector<int> treeLevel1 = levelOrderTraverse(root1);
	vector<int> treeLevel2 = levelOrderTraverse(root2); 


	sort(treeLevel1.begin(), treeLevel1.end());
	sort(treeLevel2.begin(), treeLevel2.end());

	if(treeLevel1 == treeLevel2) cout << "Yes" << endl;
	else {
		cout << "No" << endl;
	}
	return 0;	
}
