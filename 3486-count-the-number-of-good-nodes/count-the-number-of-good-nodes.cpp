class Solution {
public:
    unordered_map<int, vector<int>>graph;
    int goodNodeCount = 0;
    int dfs(int curr, vector<int>& vis){
        if(vis[curr] == 1){
            return 0;
        }
        vis[curr] = 1;
        int size = 0;
        unordered_map<int,int> freq;
        for(auto u : graph[curr]){
            if(vis[u]==0){
                int treeSize = dfs(u,vis);
                freq[treeSize]++;
                size += treeSize;
            }
        }
        if(freq.size()<=1){
            goodNodeCount++;
        }
        return size+1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n  = edges.size();
        for(int i =0;i<n;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n+1,0);
        dfs(0,vis);
        return goodNodeCount;
    }
};