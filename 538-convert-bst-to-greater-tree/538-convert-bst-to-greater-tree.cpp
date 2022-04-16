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
    int num =0;

    void helper(TreeNode* root){
        if(!root)return;
        helper(root->right);
        num += root->val;
        root->val = num;
        helper(root->left);
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return NULL;
        helper(root);
        return root;
    }
};