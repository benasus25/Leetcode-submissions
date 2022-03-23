class Solution {
public:
    int ans =0;
    
    void dfs(vector<vector<int>>&grid,int &sum, int i, int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1){
            return;
        }
        grid[i][j]=2;
        sum++;
        ans = max(ans,sum);
        dfs(grid,sum,i+1,j);
        dfs(grid,sum,i-1,j);
        dfs(grid,sum,i,j+1);
        dfs(grid,sum,i,j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    for(int i=0;i<grid.size();i++){
        for(int j =0;j<grid[0].size();j++){
        if(grid[i][j]==1){
            int sum =0; 
            dfs(grid,sum,i,j);
        }
        }
    }
    return ans;
    }
};