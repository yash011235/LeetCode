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
    const int MOD = 1e9 + 7;
    long long ans = 0;
    long long totalSum;
    long long findTotalSum(TreeNode* root){
        if(!root){
            return 0LL;
        }
        return (1LL * root->val) + findTotalSum(root->left) + findTotalSum(root->right);
    }

    long long solve(TreeNode* root){
        if(!root){
            return 0LL;
        }
        long long leftSum = solve(root->left);
        long long rightSum = solve(root->right);
        long long currSubtreeSum = (leftSum + rightSum + (1LL * root->val));
        ans = max(ans, (totalSum - currSubtreeSum) * currSubtreeSum);
        return currSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = findTotalSum(root);
        solve(root);
        ans = ans % MOD;
        return (int)ans;
    }
};