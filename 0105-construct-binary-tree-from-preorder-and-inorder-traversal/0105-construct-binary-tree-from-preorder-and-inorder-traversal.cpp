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
    unordered_map<int, int>mp;
    int n;
    TreeNode* treeBuilder(vector<int>&preorder, int left, int right, int &idx){
        if(left > right){
            return NULL;
        }
        int val = preorder[idx];
        TreeNode* curr = new TreeNode(val);
        idx++;
        if(left == right){
            return curr;
        }
        int index = mp[val];
        curr->left = treeBuilder(preorder, left, index - 1, idx);
        curr->right = treeBuilder(preorder, index + 1, right, idx);
        return curr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        int i = 0;
        return treeBuilder(preorder, 0, n - 1, i);
    }
};