class Solution {
public:
    
    int dfs(vector<vector<int>> & grid, int i, int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)return 0;
        int count = grid[i][j],ans = 0;
        grid[i][j] =0;
        ans = max(ans, dfs(grid,i+1,j));
        ans = max(ans, dfs(grid,i-1,j));
        ans = max(ans, dfs(grid,i,j+1));
        ans = max(ans, dfs(grid,i,j-1));
        grid[i][j]= count;
        return ans+count;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans = max(ans, dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};