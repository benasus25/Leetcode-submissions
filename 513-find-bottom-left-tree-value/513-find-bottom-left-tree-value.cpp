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
    
    void helper(TreeNode* root, int &ans, int h, int &maxh){
        if(!root)return;
        if(h>maxh){
            ans= root->val;
            maxh=h;
        }
        helper(root->left,ans,h+1,maxh);
        helper(root->right,ans,h+1,maxh);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1, h =0, maxh= -1;
        helper(root,ans,h,maxh);
        return ans;
    }
};