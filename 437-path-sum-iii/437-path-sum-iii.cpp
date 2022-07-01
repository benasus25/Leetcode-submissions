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
    
    int count  = 0;
    
    void helper(TreeNode* root, long long tar){
        if(!root)return;
        long long val = root->val;
        if(val==tar)count++;
        helper(root->left, tar-val);
        helper(root->right, tar-val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        helper(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};