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
    void solve(TreeNode* root, vector<int>&ans){
        if(!root){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaves1;
        solve(root1->left, leaves1);
        solve(root1->right, leaves1);
        if(root1->left == NULL && root1->right == NULL){
            leaves1.push_back(root1->val);
        }
        vector<int>leaves2;
        solve(root2->left, leaves2);
        solve(root2->right, leaves2);
        if(root2->left == NULL && root2->right == NULL){
            leaves2.push_back(root2->val);
        }
        int n1 = leaves1.size();
        int n2 = leaves2.size();
        if(n1 != n2){
            return false;
        }
        for(int i = 0; i < n1; i++){
            if(leaves1[i] != leaves2[i]){
                return false;
            }
        }
        return true;
    }
};