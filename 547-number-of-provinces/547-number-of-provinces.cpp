class Solution {
public:
    
    void dfs(vector<vector<int>>Connect, vector<bool>&vis,int i){
        vis[i]=true;
        int n= Connect.size();
        for(int j=0;j<n;j++){
            if(!vis[j]&&Connect[i][j]==1){
                dfs(Connect,vis,j);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
    int count =0, n = isConnected.size();
    if(n==0)return 0;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            dfs(isConnected,visited,i);
        }
    }
    return count;
    }
};