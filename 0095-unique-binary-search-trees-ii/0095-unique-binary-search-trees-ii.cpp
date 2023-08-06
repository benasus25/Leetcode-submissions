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
    
    vector<TreeNode*> solve(int start, int end){
        if(start>end)return {nullptr};
        vector<TreeNode*>answerList;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left = solve(start,i-1);
            vector<TreeNode*>right = solve(i+1,end);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    answerList.push_back(curr);
                }
            }
        }
        return answerList;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return n ? solve(1,n) : vector<TreeNode*>();
    }
};