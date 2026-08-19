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
    vector<vector<int>>ans;

    void solve(TreeNode* root, int targetSum, int currSum, vector<int>&path){
        if(!root){
            return;
        }
        currSum += (root->val);
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(currSum == targetSum){
                ans.push_back(path);
            }
            
            currSum -= (root->val);
        }
        // if(currSum >= targetSum){
        //     return;
        // }
        solve(root->left, targetSum, currSum, path);
        solve(root->right, targetSum, currSum, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        solve(root, targetSum, 0, path);
        return ans;
    }
};