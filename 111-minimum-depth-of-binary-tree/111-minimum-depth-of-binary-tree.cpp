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
    
    bool isleaf(TreeNode* root){
    return (!root->left and !root->right);
    }
    
    int minDepth(TreeNode* root) {
    if(root==nullptr) return 0;
    queue<TreeNode*>q;
    q.push(root);
    int len =0;
    while(!q.empty()){
        int n = q.size();
        len++;
        while(n--){
            TreeNode* temp = q.front();
            q.pop();
            if(isleaf(temp))return len;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    return len;
    }
};