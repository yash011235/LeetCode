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
    int heightLeft(TreeNode* root){
        TreeNode* temp = root;
        int h = 1;
        while(temp){
            temp = temp->left;
            h++;
        }
        return h;
    }

    int heightRight(TreeNode* root){
        TreeNode* temp = root;
        int h = 1;
        while(temp){
            temp = temp->right;
            h++;
        }
        return h;
    }

    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh = heightLeft(root->left);
        int rh = heightRight(root->right);
        if(lh == rh){
            return (1 << lh) - 1;
        }
        return 1 + solve(root->left) + solve(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return solve(root);
    }
};