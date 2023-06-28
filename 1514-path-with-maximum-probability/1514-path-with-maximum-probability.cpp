class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        vector<double>ans(n,0.0);
        queue<int>q;
        ans[start]=1.0;
        q.push(start);
        while(!q.empty()){
            int u =  q.front();
            q.pop();
            for(auto x:adj[u]){
                int node = x.first;
                double prob = x.second;
                double newprob = ans[u]*prob;
                if(newprob>ans[node]){
                    ans[node]= newprob;
                    q.push(node);
                }
            }
        }
        return ans[end];
    }
};