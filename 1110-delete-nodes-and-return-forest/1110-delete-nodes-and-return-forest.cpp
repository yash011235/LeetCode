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

    TreeNode* solve(TreeNode* root, vector<TreeNode*>&ans, unordered_set<int>&st){
        if(!root){
            return NULL;
        }
        root->left = solve(root->left, ans, st);
        root->right = solve(root->right, ans, st);
        if(st.count(root->val)){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        else{
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st(to_delete.begin(), to_delete.end());
        vector<TreeNode*>ans;
        solve(root, ans, st);
        if(!st.count(root->val)){
            ans.push_back(root);
        }
        return ans;
    }
};