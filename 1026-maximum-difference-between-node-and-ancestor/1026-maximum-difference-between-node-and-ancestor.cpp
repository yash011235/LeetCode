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
    int ans = 0;
    //mn, mx
    void solve(TreeNode* root, int mn, int mx){
        if(!root){
            return;
        }
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        ans = max(ans, mx - mn);
        solve(root->left, mn, mx);
        solve(root->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root, INT_MAX, INT_MIN);
        return ans;
    }
};