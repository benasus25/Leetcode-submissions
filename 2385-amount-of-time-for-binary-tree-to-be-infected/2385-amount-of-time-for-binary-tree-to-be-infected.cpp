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
    unordered_map<int,vector<int>>mp;
    
    void dfs(TreeNode* root, int par){
        if(!root)return;
        if(par!=-1){
            mp[par].push_back(root->val);
            mp[root->val].push_back(par);
        }
        dfs(root->left, root->val);
        dfs(root->right, root->val);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,-1);
        queue<pair<int,int>>q;
        q.push({start,0});
        unordered_set<int>vis;
        vis.insert(start);
        int ans =0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            ans = max(ans,temp.second);
            for(auto neigh : mp[temp.first]){
                if(vis.count(neigh))continue;
                q.push({neigh,temp.second+1});
                vis.insert(neigh);
            }
        }
        return ans;
    }
};