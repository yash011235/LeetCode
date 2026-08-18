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

    int countNodes(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* root, int i, int total){
        if(!root){
            return true;
        }
        if(i > total){
            return false;
        }
        bool left = dfs(root->left, 2 * i, total);
        bool right = dfs(root->right, 2 * i + 1, total);
        return (left && right);
    }

    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return dfs(root, 1, total);
    }
};