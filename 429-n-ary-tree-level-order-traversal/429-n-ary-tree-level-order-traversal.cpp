/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return {};
        vector<vector<int>>sol;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>res;
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                if(temp==nullptr) continue;
                res.push_back(temp->val);
                for(int j=0;j<temp->children.size();j++){
                    q.push(temp->children[j]);
                }
            }
            sol.push_back(res);
        }
        return sol;
    }
};