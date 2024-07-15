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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>graph;
        unordered_set<int> childSet;
        for(int i =0;i<descriptions.size();i++){
            int parent =  descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
            TreeNode* parentNode = graph.count(parent) ? graph[parent] : new TreeNode(parent);
            TreeNode* childNode = graph.count(child) ? graph[child] : new TreeNode(child);
            if (isLeft == 1)
                parentNode->left = childNode;
            else
                parentNode->right = childNode;
            graph[parent]= parentNode;
            graph[child] = childNode;
            childSet.insert(child);
        }
        for(auto &pair : graph){
            if(childSet.find(pair.first)==childSet.end()){
                return pair.second;
            }
        }
        return nullptr;
    }
};