class Solution {
public:
    
    bool iscyle(vector<vector<int>>&graph, vector<int>&vis, int i){
        if(vis[i]==1)return true;
        if(vis[i]==0){
        vis[i]=1;
        for(auto e:graph[i]){
            if(iscyle(graph,vis,e))return true;
            }
        }
        vis[i]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
    vector<vector<int>>graph(n);
    vector<int>vis(n,0);
    for(auto edge : pre){
        graph[edge[1]].push_back(edge[0]);
    }
    for(int i=0;i<n;i++){
        if(iscyle(graph, vis,i))return false;
    }    
    return true;
    }
};