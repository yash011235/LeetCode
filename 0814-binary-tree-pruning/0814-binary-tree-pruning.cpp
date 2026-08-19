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

    int total(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + total(root->left) + total(root->right);
    }

    int solve(unordered_map<int, int>&sums, TreeNode* root, int i){
        if(!root){
            return 0;
        }
        int left = solve(sums, root->left, 2 * i + 1);
        int right = solve(sums, root->right, 2 * i + 2);

        sums[i] = left + right + (root->val);
        return sums[i];
    }

    TreeNode* prune(TreeNode* root, unordered_map<int, int>&sums, int i){
        if(!root){
            return NULL;
        }
        if(!sums.count(i)){
            return NULL;
        }
        root->left = prune(root->left, sums, 2 * i + 1);
        root->right = prune(root->right, sums, 2 * i + 2);
        if(sums[i] == 0){
            return NULL;
        }
        else{
            return root;
        }
    }

    TreeNode* pruneTree(TreeNode* root) {
        int totalNodes = total(root);
        unordered_map<int, int>sums;
        solve(sums, root, 0);
        if(sums[0] == 0){
            return NULL;
        }
        prune(root, sums, 0);
        return root;
    }
};