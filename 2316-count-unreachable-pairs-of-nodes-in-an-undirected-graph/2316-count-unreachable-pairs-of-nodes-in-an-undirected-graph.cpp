class Solution {
public:
    
    void helper(vector<bool>&vis,vector<vector<int>>&graph,int i, int &c){
        vis[i]=true;
        c++;
        for(auto u:graph[i]){
            if(!vis[u]){
                helper(vis,graph,u,c);
            }
        }
        return;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>graph(n);
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        long long ans=0,total=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int count = 0;
                helper(vis,graph,i,count);
                ans +=total*count;
                total+=count;
            }    
        }
        return ans;
    }
};