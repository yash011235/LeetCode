class Solution {
public:

    bool dfs(TreeNode* root){
        if(!root){
            return false;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if(!left){
            root->left = NULL;
        }
        if(!right){
            root->right = NULL;
        }
        return (root->val) || left || right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(!dfs(root)){
            return NULL;
        }
        return root;
    }
};