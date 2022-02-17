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
    bool helper(TreeNode* tem1,TreeNode* tem2){
        if(!tem1&&!tem2)return true;
        else if(!tem1||!tem2)return false;
        else if(tem1->val!=tem2->val) return false;
        return (helper(tem1->left,tem2->right)&&helper(tem1->right,tem2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root->left,root->right);
    }
};