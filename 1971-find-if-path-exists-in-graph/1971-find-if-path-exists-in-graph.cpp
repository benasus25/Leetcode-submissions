class Solution {
public:
    
    bool dfs(vector<vector<int>>&graph, int src, int dest,vector<bool>&vis){
        if(src==dest)return true;
        if(vis[src])return false;
        vis[src]=true;
        for(int i=0;i<graph[src].size();i++){
            if(dfs(graph,graph[src][i],dest,vis))return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        return dfs(graph,source,destination,visited);
    }
};