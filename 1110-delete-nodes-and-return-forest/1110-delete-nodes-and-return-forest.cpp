/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, unordered_set<int>&st, vector<TreeNode*>&res){
        if(!root){
            return root;
        }
        root->left = solve(root->left, st, res);
        root->right = solve(root->right, st, res);
        if(st.count(root->val)){
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st(to_delete.begin(), to_delete.end());
        vector<TreeNode*>res;
        solve(root, st, res);
        if(!st.count(root->val)){
            res.push_back(root);
        }
        return res;
    }
};