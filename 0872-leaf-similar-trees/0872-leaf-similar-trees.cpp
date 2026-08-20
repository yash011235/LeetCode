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
    void solve(TreeNode* root, vector<int>&leaves){
        if(!root){
            return;
        }
        solve(root->left, leaves);
        solve(root->right, leaves);
        if(!root->left && !root->right){
            leaves.push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaves1;
        vector<int>leaves2;
        solve(root1->left, leaves1);
        solve(root1->right, leaves1);
        if(leaves1.empty()){
            leaves1.push_back(root1->val);
        }
        solve(root2->left, leaves2);
        solve(root2->right, leaves2);
        if(leaves2.empty()){
            leaves2.push_back(root2->val);
        }
        int n = leaves1.size();
        int m = leaves2.size();
        if(n != m){
            return false;
        }
        for(int i = 0; i < n; i++){
            if(leaves1[i] != leaves2[i]){
                return false;
            }
            cout << leaves1[i] << " " << leaves2[i] << "\n";
        }
        return true;
    }
};