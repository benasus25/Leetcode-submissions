class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n);
        vector<int>inorder(n,0);
        for(int i=0;i<pre.size();i++){
            graph[pre[i][1]].push_back(pre[i][0]);
            inorder[pre[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!inorder[i])q.push(i);
        }
        while(!q.empty()){
            int num = q.front();
            for( auto &u:graph[num]){
                inorder[u]--;
                if(inorder[u]==0)q.push(u);
            }
            n--;
            q.pop();
        }
        if(n==0)return true;
        return false;
    }
};