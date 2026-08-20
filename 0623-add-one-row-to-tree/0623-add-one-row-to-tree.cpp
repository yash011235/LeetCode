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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        int prev = depth - 1;
        int curr = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            if(curr == prev){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    TreeNode* n = new TreeNode(val);
                    TreeNode* temp = node->left;
                    node->left = n;
                    n->left = temp;
                    q.push(n);
                    TreeNode* n1 = new TreeNode(val);
                    TreeNode* temp1 = node->right;
                    node->right = n1;
                    n1->right = temp1;
                    q.push(n1);
                }
            }
            else{
                int size = q.size();
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
            }
            curr++;
        }
        return root;
    }
};