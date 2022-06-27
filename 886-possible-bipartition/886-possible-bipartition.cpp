class Solution {
public:
    
    bool helper(vector<vector<int>>&graph, vector<int>&col, int i, int c){
        col[i]=c;
        for(auto u:graph[i]){
            if(col[i]==col[u])return false;
            if(col[u]==0){
                if(!helper(graph,col,u,-c))return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n);
        for(auto u:dislikes){
            graph[u[0]-1].push_back(u[1]-1);
            graph[u[1]-1].push_back(u[0]-1);
        }
        vector<int>col(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(col[i]!=0)continue;
            q.push(i);
            col[i]=1;
            while(!q.empty()){
                int top = q.front();
                q.pop();
                int c = col[top];
                for(auto u:graph[top]){
                    if(col[u]==c)return false;
                    if(col[u]==0){
                        q.push(u);
                        col[u]=-c;
                    }
                }
            }
        }
        return true;
    }
};