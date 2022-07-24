class Solution {
public:
    
    bool dfs(vector<vector<int>>&graph, int i, vector<int>&vis){
        if(vis[i]==1)return true;
        if(vis[i]==0){
            vis[i]=1;
            for(auto &u:graph[i]){
                if(dfs(graph,u,vis))return true;
            }
        }
        vis[i]=2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>graph(numCourses);
        for(int i=0;i<pre.size();i++){
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(graph,i,vis))return false;
            }
        }
        return true;
    }
};