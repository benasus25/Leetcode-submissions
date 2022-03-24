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
    vector<int>res;
    
    void helper(TreeNode* root,int h){
        if(!root)return;
        if(h==res.size())res.push_back(root->val);
        helper(root->right,h+1);
        helper(root->left,h+1);
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
    helper(root,0);
    return res;
    }
};