/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// find k distance nodes 

class Solution {
public:
    
    void findParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        if(root == NULL) return;
        
        if(root->left) {
            parent[root->left] = root;
            findParentNodes(root->left, parent);
        }
        if(root->right) {
            parent[root->right] = root;
            findParentNodes(root->right, parent);
        }
    }
    
    void dfs(TreeNode* root, int K, unordered_map<TreeNode*, TreeNode*> &parent, unordered_set<TreeNode*>&visited, vector<int>&res) {
        if(root == NULL) return;
        if(visited.find(root) != visited.end()) return;
        
        visited.insert(root);
        
        if(K == 0) {
            res.push_back(root->val);
        }
        dfs(root->left, K - 1, parent, visited, res);
        dfs(root->right, K - 1, parent, visited, res);
        dfs(parent[root], K - 1, parent, visited, res);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        vector<int>res;
        
        findParentNodes(root, parent);
        dfs(target, K, parent, visited, res);
        
        return res;
    }
};